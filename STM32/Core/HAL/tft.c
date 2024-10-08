#include "tft.h"

//ascii字符,大小为8*16
uint8_t TFT_chara[][16] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x18,0x18,0x00,0x00},/*"!",1*/
{0x00,0x48,0x6C,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
{0x00,0x00,0x00,0x24,0x24,0x24,0x7F,0x12,0x12,0x12,0x7F,0x12,0x12,0x12,0x00,0x00},/*"#",3*/
{0x00,0x00,0x08,0x1C,0x2A,0x2A,0x0A,0x0C,0x18,0x28,0x28,0x2A,0x2A,0x1C,0x08,0x08},/*"$",4*/
{0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x15,0x2A,0x58,0x54,0x54,0x54,0x22,0x00,0x00},/*"%",5*/
{0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x11,0x91,0x6E,0x00,0x00},/*"&",6*/
{0x00,0x06,0x06,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00},/*"(",8*/
{0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00},/*")",9*/
{0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00},/*"*",10*/
{0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x7F,0x08,0x08,0x08,0x08,0x00,0x00,0x00},/*"+",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x04,0x03},/*",",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00},/*".",14*/
{0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00},/*"/",15*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",16*/
{0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"1",17*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00},/*"2",18*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00},/*"3",19*/
{0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00},/*"4",20*/
{0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00},/*"5",21*/
{0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"6",22*/
{0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00},/*"7",23*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00},/*"8",24*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00},/*"9",25*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x04},/*";",27*/
{0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00},/*"<",28*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},/*"=",29*/
{0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00},/*">",30*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x40,0x20,0x10,0x10,0x00,0x18,0x18,0x00,0x00},/*"?",31*/
{0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x2D,0x42,0x22,0x1C,0x00,0x00},/*"@",32*/
{0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00},/*"A",33*/
{0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"B",34*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00},/*"C",35*/
{0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"D",36*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00},/*"E",37*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00},/*"F",38*/
{0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00},/*"G",39*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"H",40*/
{0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"I",41*/
{0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F},/*"J",42*/
{0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00},/*"K",43*/
{0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00},/*"L",44*/
{0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00},/*"M",45*/
{0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00},/*"N",46*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00},/*"O",47*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",48*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x4D,0x53,0x32,0x1C,0x60,0x00},/*"Q",49*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00},/*"R",50*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00},/*"S",51*/
{0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"T",52*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"U",53*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00},/*"V",54*/
{0x00,0x00,0x00,0x6B,0x49,0x49,0x49,0x49,0x55,0x55,0x36,0x22,0x22,0x22,0x00,0x00},/*"W",55*/
{0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00},/*"X",56*/
{0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"Y",57*/
{0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00},/*"Z",58*/
{0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00},/*"[",59*/
{0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40},/*"\",60*/
{0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00},/*"]",61*/
{0x00,0x38,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},/*"_",63*/
{0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x78,0x44,0x42,0x42,0xFC,0x00,0x00},/*"a",65*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00},/*"b",66*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00},/*"c",67*/
{0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x78,0x44,0x42,0x42,0x42,0x64,0xD8,0x00,0x00},/*"d",68*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x02,0x02,0x42,0x3C,0x00,0x00},/*"e",69*/
{0x00,0x00,0x00,0xF0,0x88,0x08,0x08,0x7E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"f",70*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C},/*"g",71*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"h",72*/
{0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"i",73*/
{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E},/*"j",74*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x72,0x12,0x0A,0x16,0x12,0x22,0x77,0x00,0x00},/*"k",75*/
{0x00,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"l",76*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00},/*"m",77*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"n",78*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"o",79*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x22,0x1E,0x02,0x07},/*"p",80*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0xE0},/*"q",81*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00},/*"r",82*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00},/*"s",83*/
{0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x30,0x00,0x00},/*"t",84*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00},/*"u",85*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x08,0x08,0x00,0x00},/*"v",86*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEB,0x49,0x49,0x55,0x55,0x22,0x22,0x00,0x00},/*"w",87*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x24,0x18,0x18,0x18,0x24,0x6E,0x00,0x00},/*"x",88*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x18,0x08,0x08,0x07},/*"y",89*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00},/*"z",90*/
{0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00},/*"{",91*/
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10},/*"|",92*/
{0x00,0x06,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x06,0x00},/*"}",93*/
{0x0C,0x32,0xC2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
};

// 此处定义缓冲区图像的颜色
uint16_t frame_color[4] = {
	0, 0xFFCF, 0xFA6A, 0x87E0
};

//发送1字节数据
void TFT_WriteData(TFT* obj, uint8_t data)
{
    HAL_GPIO_WritePin(obj->dc_gpio, obj->dc_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(obj->hspi, &data, 1, 100);
    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_SET);
}

//发送2字节数据
// 传入u16改为分别传高低位u8, 减少单色绘图函数进行位运算的次数
void TFT_WriteData16(TFT* obj, uint16_t data)
{
	uint8_t high = data >> 8;
	uint8_t low = data & 0xFF;
    HAL_GPIO_WritePin(obj->dc_gpio, obj->dc_pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(obj->hspi, &high, 1, 100);
    // HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_SET);

    // HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(obj->hspi, &low, 1, 100);
    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_SET);
}

//发送命令
void TFT_WriteCMD(TFT* obj, uint8_t cmd)
{
    HAL_GPIO_WritePin(obj->dc_gpio, obj->dc_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(obj->hspi, &cmd, 1, 100);
    HAL_GPIO_WritePin(obj->cs_gpio, obj->cs_pin, GPIO_PIN_SET);
}

TFT* TFT_Init(SPI_HandleTypeDef* hspi, GPIO_TypeDef *cs_gpio, uint16_t cs_pin,
										GPIO_TypeDef *dc_gpio, uint16_t dc_pin,
										GPIO_TypeDef *bl_gpio, uint16_t bl_pin,
										GPIO_TypeDef *re_gpio, uint16_t re_pin)
{
	TFT* obj = (TFT*)malloc(sizeof(TFT));
	memset(obj, 0, sizeof(TFT));
	obj->hspi = hspi;
	obj->cs_gpio = cs_gpio;
	obj->cs_pin = cs_pin;
	obj->dc_gpio = dc_gpio;
	obj->dc_pin = dc_pin;
	obj->bl_gpio = bl_gpio;
	obj->bl_pin = bl_pin;
	obj->re_gpio = re_gpio;
	obj->re_pin = re_pin;

	return obj;
}

void TFT_HardInit(TFT* obj){
	HAL_GPIO_WritePin(obj->bl_gpio, obj->bl_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(obj->re_gpio, obj->re_pin, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(obj->re_gpio, obj->re_pin, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(obj->bl_gpio, obj->bl_pin, GPIO_PIN_SET);

	TFT_WriteCMD(obj, 0x01); 
	HAL_Delay(50); 
	TFT_WriteCMD(obj, 0x11); 
	HAL_Delay(50); 
	
	//display and color format setting
	TFT_WriteCMD(obj, 0x36);

	if(USE_HORIZONTAL == 0)TFT_WriteData(obj, 0x00);
	else if(USE_HORIZONTAL == 1)TFT_WriteData(obj, 0xC0);
	else if(USE_HORIZONTAL == 2)TFT_WriteData(obj, 0x70);
	else TFT_WriteData(obj, 0xA0);

	TFT_WriteCMD(obj, 0x3A);
	TFT_WriteData(obj, 0x05);

	//frame rate setting
	TFT_WriteCMD(obj, 0xB2);
	TFT_WriteData(obj, 0x0C);
	TFT_WriteData(obj, 0x0C);
	TFT_WriteData(obj, 0x00);
	TFT_WriteData(obj, 0x33);
	TFT_WriteData(obj, 0x33); 

	TFT_WriteCMD(obj, 0xB7); 
	TFT_WriteData(obj, 0x35);  

	//power setting
	TFT_WriteCMD(obj, 0xBB);
	TFT_WriteData(obj, 0x35);

	TFT_WriteCMD(obj, 0xC0);
	TFT_WriteData(obj, 0x2C);

	TFT_WriteCMD(obj, 0xC2);
	TFT_WriteData(obj, 0x01);

	TFT_WriteCMD(obj, 0xC3);
	TFT_WriteData(obj, 0x13);   

	TFT_WriteCMD(obj, 0xC4);
	TFT_WriteData(obj, 0x20);  

	TFT_WriteCMD(obj, 0xC6); 
	TFT_WriteData(obj, 0x0F);    

	TFT_WriteCMD(obj, 0xCA); 
	TFT_WriteData(obj, 0x0F);  

	TFT_WriteCMD(obj, 0xC8); 
	TFT_WriteData(obj, 0x08);  

	TFT_WriteCMD(obj, 0x55); 
	TFT_WriteData(obj, 0x90);  

	TFT_WriteCMD(obj, 0xD0); 
	TFT_WriteData(obj, 0xA4);  
	TFT_WriteData(obj, 0xA1);  

	//gamma setting
	TFT_WriteCMD(obj, 0xE0);
	TFT_WriteData(obj, 0xD0);
	TFT_WriteData(obj, 0x00);
	TFT_WriteData(obj, 0x06);
	TFT_WriteData(obj, 0x09);
	TFT_WriteData(obj, 0x0B);
	TFT_WriteData(obj, 0x2A);
	TFT_WriteData(obj, 0x3C);
	TFT_WriteData(obj, 0x55);
	TFT_WriteData(obj, 0x4B);
	TFT_WriteData(obj, 0x08);
	TFT_WriteData(obj, 0x16);
	TFT_WriteData(obj, 0x14);
	TFT_WriteData(obj, 0x19);
	TFT_WriteData(obj, 0x20);

	TFT_WriteCMD(obj, 0xE1);
	TFT_WriteData(obj, 0xD0);
	TFT_WriteData(obj, 0x00);
	TFT_WriteData(obj, 0x06);
	TFT_WriteData(obj, 0x09);
	TFT_WriteData(obj, 0x0B);
	TFT_WriteData(obj, 0x29);
	TFT_WriteData(obj, 0x36);
	TFT_WriteData(obj, 0x54);
	TFT_WriteData(obj, 0x4B);
	TFT_WriteData(obj, 0x0D);
	TFT_WriteData(obj, 0x16);
	TFT_WriteData(obj, 0x14);
	TFT_WriteData(obj, 0x21);
	TFT_WriteData(obj, 0x20);

	// TFT_WriteCMD(obj, 0x21);
	TFT_WriteCMD(obj, 0x29);

	// 清屏
	TFT_Fill(obj, 0, 0, 320, 241, 0);
}

void TFT_SetPos(TFT* obj, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	//x1写0无法更新,需要写1
    #if (USE_HORIZONTAL == 0 || USE_HORIZONTAL == 1)
        TFT_WriteCMD(obj, 0x2A);
        TFT_WriteData16(obj, x1);
        TFT_WriteData16(obj, x2);
        TFT_WriteCMD(obj, 0x2B);
        TFT_WriteData16(obj, y1);
        TFT_WriteData16(obj, y2);
        TFT_WriteCMD(obj, 0x2C);
    #else
        TFT_WriteCMD(obj, 0x2A);
        TFT_WriteData16(obj, x1);
        TFT_WriteData16(obj, x2);
        TFT_WriteCMD(obj, 0x2B);
        TFT_WriteData16(obj, y1);
        TFT_WriteData16(obj, y2);
        TFT_WriteCMD(obj, 0x2C);
    #endif

}

//RGB转565颜色
uint16_t RGB2565(uint8_t red, uint8_t green, uint8_t blue)
{
	return ( (red >> 3 << 11) + (green >> 2 << 5) + (blue >> 3));
}

// 填充
void TFT_Fill(TFT* obj, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	TFT_SetPos(obj, x1, y1 - 1, x2, y2 - 1);
	for(uint16_t i = x1; i <= x2 - 1; i++)
	{
		for(uint16_t j = y1; j <= y2 - 1; j++)
			TFT_WriteData16(obj, color);
	}
}

//画线
void TFT_DrawLine(TFT* obj, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{	
	if(x1 > x2){
		uint8_t temp = x2;
		x2 = x1;
		x1 = temp;
		temp = y2;
		y2 = y1;
		y1 = temp;
	}
	//竖直线
	if(x1 == x2)
	{
		for(uint16_t y = y1; y <= y2 - 1; y++)
			{
				TFT_SetPos(obj, x1, y, x1, y);
				TFT_WriteData16(obj, color);
			}
	}
	else
	{
		float k = (y2 - y1) * 1.0 / (x2 - x1);
		float b = y1 - k * x1;
		if(fabs(k) > 1){
			if(y1 > y2){
				uint8_t temp = x2;
				x2 = x1;
				x1 = temp;
				temp = y2;
				y2 = y1;
				y1 = temp;
			}
            for(uint16_t y = y1; y <= y2 - 1; y++){
                uint16_t x = (uint16_t)round((y - b) / k);
                TFT_SetPos(obj, x, y, x, y);
				TFT_WriteData16(obj, color);
            }
		} else {
			for(uint16_t x = x1; x <= x2 - 1; x++)
			{
				uint16_t y = (uint16_t)round(k * x + b);
				TFT_SetPos(obj, x, y, x, y);
				TFT_WriteData16(obj, color);
			}
		}

	}
}

//画圆弧
void TFT_DrawArc(TFT* obj, uint16_t centerx, uint16_t centery, uint16_t radius, int16_t deg1, int16_t deg2, uint16_t color)
{
	if(deg1 > deg2){
		uint8_t temp = deg2;
		deg2 = deg1;
		deg1 = temp;
	}
		for(int16_t deg = deg1; deg <= deg2; deg++)
		{
			uint16_t x = round(centerx + radius * cos(deg * PI / 180));
			uint16_t y = round(centery - radius * sin(deg * PI / 180));
			if(x >= 1 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			{
				TFT_SetPos(obj, x, y, x, y);
				TFT_WriteData16(obj, color);
			}
		}
}

//写ascii字符串
void TFT_DrawStr_ascii(TFT* obj, uint16_t x, uint16_t y, char* str, uint16_t color, uint8_t max_len)
{
	uint8_t len = strlen(str);
	if(len > max_len) len = max_len;
	for(int i = 0; i <= len - 1; i++)
	{
		TFT_SetPos(obj, x + 8 * i, y, x + 8 * i + 7, y + 15);
		for(int j = 0; j <= 15; j++)
			for(int k = 0; k <= 7; k++) TFT_WriteData16(obj, TFT_chara[str[i] - ' '][j] & (1 << k) ? color : 0);
	}
}

//通过读取字库文件写单个字符(16*16), 其中buf为32个uint8_t
void TFT_DrawStr_fonttype(TFT* obj, uint16_t x, uint16_t y, uint8_t* buf, uint16_t color)
{
	TFT_SetPos(obj, x, y, x + 15, y + 15);
	for(int j = 0; j <= 31; j++){
			for(int k = 7; k >= 0; k--) TFT_WriteData16(obj, buf[j] & (1 << k) ? color : 0);
	}
}

// 加载缓冲区内图片, x y为左上角坐标
void TFT_DrawFrame(TFT* obj, uint16_t x, uint16_t y)
{
	TFT_SetPos(obj, x, y, x + FRAME_BUF_SIDE - 1, y + FRAME_BUF_SIDE - 1);
	for(int j = 0; j < FRAME_BUF_SIDE; j++){
		for(int i = 0; i < FRAME_BUF_SIDE; i++){
			TFT_WriteData16(obj, frame_color[(obj->frame_buf[j][i / 4] >> (i % 4 * 2)) % 4]);
		}
	}
}

// 加载缓冲区内图片(仅加载部分)
void TFT_DrawFramePart(TFT* obj, uint16_t x, uint16_t y)
{
	// 限制加载部分坐标
	if(obj->frame_x1 < 0) obj->frame_x1 = 0;
	if(obj->frame_y1 < 0) obj->frame_y1 = 0;
	if(obj->frame_x2 > FRAME_BUF_SIDE - 1) obj->frame_x2 = FRAME_BUF_SIDE - 1;
	if(obj->frame_y2 > FRAME_BUF_SIDE - 1) obj->frame_y2 = FRAME_BUF_SIDE - 1;
	TFT_SetPos(obj, x + obj->frame_x1, y + obj->frame_y1, x + obj->frame_x2, y + obj->frame_y2);
	for(int j = obj->frame_y1; j <= obj->frame_y2; j++){
		for(int i = obj->frame_x1; i <= obj->frame_x2; i++){
			TFT_WriteData16(obj, frame_color[(obj->frame_buf[j][i / 4] >> (i % 4 * 2)) % 4]);
		}
	}
}


//数字转字符串(字符串有效长度不超过6位)
char* TFT_Itoa(int16_t num)
{
	static char str[7] = "";
	memset(str, 0, 7 * sizeof(char));

	if(num == 0)
    {
        strcat(str, "0     ");
        return str;
    }
	else if(num < 0)
	{
		strcat(str, "-");
		num = -num;
	}

	int digit = (int)(log10(num));
	for(int i = digit; i >= 0; i--)
	{
		char temp[2] = "";
		temp[0] = num / pow(10, i) + '0';
		strcat(str, temp);
		num %= (int)pow(10, i);
	}

	//补空格
	for(int i = 0; i <= 5; i++)
	{
		if(!str[i]) str[i] = ' ';
	}
	return str;
}