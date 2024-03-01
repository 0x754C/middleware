#ifndef __SC8238_CMOS_PARAM_H_
#define __SC8238_CMOS_PARAM_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include <linux/cvi_vip_cif.h>
#include <linux/cvi_vip_snsr.h>
#include "cvi_type.h"
#include "cvi_sns_ctrl.h"
#include "sc8238_cmos_ex.h"

static const SC8238_MODE_S g_astSC8238_mode[SC8238_MODE_NUM] = {
	[SC8238_MODE_2160P30] = {
		.name = "2160p30",
		.astImg[0] = {
			.stSnsSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stMaxSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
		},
		.f32MaxFps = 30,
		.f32MinFps = 1.03, /* 2250 * 30 / 0xFFFF */
		.u32HtsDef = 4200,
		.u32VtsDef = 2250,
		.stExp[0] = {
			.u16Min = 2,
			.u16Max = (2250 * 2 - 10),
			.u16Def = 400,
			.u16Step = 1,
		},
		.stAgain[0] = {
			.u16Min = 64,
			.u16Max = 8063,
			.u16Def = 64,
			.u16Step = 1,
		},
		.stDgain[0] = {
			.u16Min = 128,
			.u16Max = 4092,
			.u16Def = 128,
			.u16Step = 4,
		},
	},
	[SC8238_MODE_2160P15_WDR] = {
		.name = "2160p15wdr",
		.astImg[0] = {
			.stSnsSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stMaxSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
		},
		.astImg[1] = {
			.stSnsSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 3840,
				.u32Height = 2160,
			},
			.stMaxSize = {
				.u32Width = 3840,
				.u32Height = 2160,
			},
		},
		.f32MaxFps = 15,
		.f32MinFps = 1.03, /* 4500 * 15 / 0xFFFF */
		.u32HtsDef = 4200,
		.u32VtsDef = 4500,
		/* When u16SexpMaxReg increases, the v-blanking decreases.
		 * Apply the safe value with sufficient v-blanking.
		 */
		.u16SexpMaxReg = 0x80,
	},
};

static ISP_CMOS_NOISE_CALIBRATION_S g_stIspNoiseCalibratio = {.CalibrationCoef = {
	{	// iso 100
		{0.05527953803539276123,	5.70521783828735351563}, //B: slope, intercept
		{0.05711727589368820190,	4.41583013534545898438}, //Gb: slope, intercept
		{0.05705824121832847595,	4.53220176696777343750}, //Gr: slope, intercept
		{0.05774152278900146484,	5.21610784530639648438}, //R: slope, intercept
	},
	{	// iso 200
		{0.06394825875759124756,	12.03454017639160156250}, //B: slope, intercept
		{0.06376964598894119263,	11.65788936614990234375}, //Gb: slope, intercept
		{0.06392037868499755859,	11.75535678863525390625}, //Gr: slope, intercept
		{0.06612074375152587891,	11.83661651611328125000}, //R: slope, intercept
	},
	{	// iso 400
		{0.06944000720977783203,	17.28322982788085937500}, //B: slope, intercept
		{0.06644775718450546265,	17.78941917419433593750}, //Gb: slope, intercept
		{0.06679775565862655640,	17.73714256286621093750}, //Gr: slope, intercept
		{0.07118742913007736206,	17.44178009033203125000}, //R: slope, intercept
	},
	{	// iso 800
		{0.08003900945186614990,	26.03638839721679687500}, //B: slope, intercept
		{0.07184640318155288696,	29.53101348876953125000}, //Gb: slope, intercept
		{0.07263082265853881836,	29.05339622497558593750}, //Gr: slope, intercept
		{0.08078674226999282837,	26.37462615966796875000}, //R: slope, intercept
	},
	{	// iso 1600
		{0.09421897679567337036,	43.55544281005859375000}, //B: slope, intercept
		{0.07994629442691802979,	51.68421554565429687500}, //Gb: slope, intercept
		{0.08095411956310272217,	50.18256378173828125000}, //Gr: slope, intercept
		{0.09372865408658981323,	44.73367691040039062500}, //R: slope, intercept
	},
	{	// iso 3200
		{0.14872977137565612793,	73.05225372314453125000}, //B: slope, intercept
		{0.12847416102886199951,	85.47373962402343750000}, //Gb: slope, intercept
		{0.13237676024436950684,	82.10460662841796875000}, //Gr: slope, intercept
		{0.15353925526142120361,	73.31748962402343750000}, //R: slope, intercept
	},
	{	// iso 6400
		{0.18389481306076049805,	119.01705932617187500000}, //B: slope, intercept
		{0.14243574440479278564,	150.03631591796875000000}, //Gb: slope, intercept
		{0.15078565478324890137,	143.24606323242187500000}, //Gr: slope, intercept
		{0.18630988895893096924,	123.02956390380859375000}, //R: slope, intercept
	},
	{	// iso 12800
		{0.27536603808403015137,	174.33103942871093750000}, //B: slope, intercept
		{0.18336220085620880127,	235.21069335937500000000}, //Gb: slope, intercept
		{0.20121896266937255859,	220.82307434082031250000}, //Gr: slope, intercept
		{0.27374020218849182129,	189.80323791503906250000}, //R: slope, intercept
	},
	{	// iso 25600
		{0.45846450328826904297,	244.23806762695312500000}, //B: slope, intercept
		{0.28208819031715393066,	341.76940917968750000000}, //Gb: slope, intercept
		{0.32906025648117065430,	305.96450805664062500000}, //Gr: slope, intercept
		{0.42171603441238403320,	285.55218505859375000000}, //R: slope, intercept
	},
	{	// iso 51200
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 102400
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 204800
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 409600
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 819200
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 1638400
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
	{	// iso 3276800
		{0.71897524595260620117,	305.30139160156250000000}, //B: slope, intercept
		{0.47197058796882629395,	425.15866088867187500000}, //Gb: slope, intercept
		{0.58856225013732910156,	350.56115722656250000000}, //Gr: slope, intercept
		{0.61702102422714233398,	390.61053466796875000000}, //R: slope, intercept
	},
} };

static ISP_CMOS_BLACK_LEVEL_S g_stIspBlcCalibratio = {
	.bUpdate = CVI_TRUE,
	.blcAttr = {
		.Enable = 1,
		.enOpType = OP_TYPE_AUTO,
		.stManual = {273, 273, 273, 273, 1097, 1097, 1097, 1097},
		.stAuto = {
			{272, 273, 269, 267, 267, 264, 260, 263, /*8*/312, 444, 523, 499, 534, 497, 452, 481},
			{273, 274, 271, 272, 279, 290, 312, 344, /*8*/434, 641, 750, 724, 783, 735, 681, 723},
			{272, 274, 269, 268, 268, 265, 264, 271, /*8*/276, 392, 474, 454, 488, 454, 413, 439},
			{273, 275, 272, 274, 280, 294, 320, 360, /*8*/401, 594, 708, 686, 743, 702, 644, 689},
			{1097, 1097, 1096, 1095, 1095, 1095, 1093, 1094,
				/*8*/1108, 1149, 1174, 1166, 1178, 1165, 1151, 1160},
			{1097, 1097, 1097, 1097, 1099, 1102, 1108, 1118,
				/*8*/1145, 1214, 1254, 1244, 1266, 1248, 1228, 1244},
			{1097, 1097, 1096, 1096, 1096, 1095, 1095, 1097,
				/*8*/1098, 1132, 1158, 1152, 1163, 1152, 1139, 1147},
			{1097, 1098, 1097, 1097, 1099, 1103, 1111, 1123,
				/*8*/1135, 1198, 1238, 1230, 1251, 1236, 1215, 1231},
		},
	},
};

struct combo_dev_attr_s sc8238_rx_attr = {
	.input_mode = INPUT_MODE_MIPI,
	.mac_clk = RX_MAC_CLK_400M,
	.mipi_attr = {
		.raw_data_type = RAW_DATA_10BIT,
		.lane_id = {3, 4, 2, 0, 1},
		.wdr_mode = CVI_MIPI_WDR_MODE_VC,
		.dphy = {
			.enable = 1,
			.hs_settle = 8,
		},
	},
	.mclk = {
		.cam = 0,
		.freq = CAMPLL_FREQ_27M,
	},
	.devno = 0,
};

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif /* __SC8238_CMOS_PARAM_H_ */
