/*
 * Driver for the PCM3060 codec
 *
 * Author:	Jon Ronen-Drori <jon_ronen@yahoo.com>
 *		Copyright 2014
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */


#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#include <sound/soc.h>

static struct snd_soc_dai_driver pcm3060_dai = {
	.name = "pcm3060-hifi",
	.playback = {
		.channels_min = 2,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_48000,
		.formats = SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE
	},
	.capture = {
		.channels_min = 2,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_48000,
		.formats = SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE
	},
};

static struct snd_soc_codec_driver soc_codec_dev_pcm3060;

static int pcm3060_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_pcm3060,
			&pcm3060_dai, 1);
}

static int pcm3060_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static struct platform_driver pcm3060_codec_driver = {
	.probe 		= pcm3060_probe,
	.remove 	= pcm3060_remove,
	.driver		= {
		.name	= "pcm3060-codec",
		.owner	= THIS_MODULE,
	},
};

module_platform_driver(pcm3060_codec_driver);

MODULE_DESCRIPTION("ASoC PCM3060 codec driver");
MODULE_AUTHOR("Jon Ronen-Drori <jon_ronen@yahoo.com>");
MODULE_LICENSE("GPL v2");
