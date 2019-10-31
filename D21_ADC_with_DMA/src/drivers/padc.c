#include "padc.h"

static uint16_t raw_adc_values[P_ADC_BUFFER_SIZE];

static struct adc_module adc_mod;
static struct dma_resource adc_resource;

COMPILER_ALIGNED(16)
DmacDescriptor adc_descriptor SECTION_DMAC_DESCRIPTOR;

void padc_init(void)
{
	// configure adc
	struct adc_config adc_conf;
	adc_get_config_defaults(&adc_conf);
	adc_conf.gain_factor = P_ADC_GAIN_FACTOR;
	adc_conf.resolution = P_ADC_RESOLUTION;
	adc_conf.clock_prescaler = P_ADC_CLOCK_PRESCALAR;
	adc_conf.reference = P_ADC_VREF;
	adc_conf.positive_input = P_ADC_POSITIVE_INPUT_PIN;
	adc_conf.negative_input = P_ADC_NEGATIVE_INPUT_PIN;
	adc_conf.freerunning = true;
	adc_conf.left_adjust = false;
	
	adc_init(&adc_mod, ADC, &adc_conf);
	adc_enable(&adc_mod);
	
	// configure dma resource
	struct dma_resource_config dma_resource_conf;
	dma_get_config_defaults(&dma_resource_conf);
	dma_resource_conf.peripheral_trigger = ADC_DMAC_ID_RESRDY;
	dma_resource_conf.trigger_action = DMA_TRIGGER_ACTION_BLOCK;
	// allocate dma resource
	dma_allocate(&adc_resource, &dma_resource_conf);
	// setup transfer descriptor
	struct dma_descriptor_config dma_desc_conf;
	dma_descriptor_get_config_defaults(&dma_desc_conf);
	dma_desc_conf.beat_size = DMA_BEAT_SIZE_HWORD;	// 16 bit
	dma_desc_conf.dst_increment_enable = true;
	dma_desc_conf.src_increment_enable = false;
	dma_desc_conf.block_transfer_count = sizeof(raw_adc_values) / 2;
	dma_desc_conf.source_address = (uint32_t)(&adc_mod.hw->RESULT.reg);
	dma_desc_conf.destination_address = (uint32_t)(raw_adc_values + (sizeof(raw_adc_values) / 2));
	dma_desc_conf.next_descriptor_address = (uint32_t)&adc_descriptor;
	dma_descriptor_create(&adc_descriptor, &dma_desc_conf);
	dma_add_descriptor(&adc_resource, &adc_descriptor);
}

void padc_start(void)
{
	adc_start_conversion(&adc_mod);
	dma_start_transfer_job(&adc_resource);
}

float padc_get_voltage(void)
{
	uint16_t raw = padc_get_raw();
	// raw reading / 2^n * Vref
	// n = bit resolution
	// vref = 1/1.48 * Vcc
	// Vcc is supposed to be 3.3, which would give a Vref of 2.2297
	// My vcc is dipping a bit low at 3.26-3.28 so my vref is slightly lower.
	return (float)((float)raw / 4096.0f * 2.2027f);
}

uint16_t padc_get_raw(void)
{
	uint32_t sum = 0;
	for(int ind = 0; ind < P_ADC_OVERSAMPLE_RATE; ind++)
	{
		//printf("Raw: [%d]: %u\r\n", ind, raw_adc_values[ind]);
		sum += (uint32_t)raw_adc_values[ind];
	}
	sum /= P_ADC_OVERSAMPLE_RATE;
	return (uint16_t)sum;
}