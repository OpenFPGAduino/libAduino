/*
 * lcd.c
 *
 *  Created on: Aug 10, 2013
 *      Author: zhizhouli
 */
#include <linux/fb.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "lcd.h"
int fbfd = 0;
char* fbp;
long int screensize = 0;
void lcd_clear(char red, char green, char blue)
{
	int i;
	char* point = fbp;
	for(i = 0; i< screensize/4; i++)
	{
		*(point++) = blue;
		*(point++) = green;
		*(point++) = red;
		point++;
	}
}
void lcd_init(void)
{
	//int i;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;

	/*打开设备文件*/
	fbfd = open("/dev/fb0", O_RDWR);
	/*取得屏幕相关参数*/
	ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
	ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
	/*计算屏幕缓冲区大小*/
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	/*映射屏幕缓冲区到用户地址空间*/
	fbp = (char*) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd,
			0);
	//clear the lcd
	lcd_clear(255,255,255);
	/*下面可通过 fbp指针读写缓冲区*/
}

void lcd_set_point(int x, int y, char red, char green, char blue)
{
	char *point;
	x = 479 - x;
	y = 271 - y;
	point = fbp + x*4 + 480 * y * 4;
	*(point++) = blue;
	*(point++) = green;
	*point = red;
}

void lcd_clear_box(int x, int y,int length, int height, char red, char green, char blue)
{
	char *p1;
	char *p2;
	char *p3;
	int i, j;
	x = 479 - x;
	y = 271 - y;
	p1 = fbp + x*4 + 480 * y * 4;
	for (j = 0; j < height; j++) {
		p2 = p1 - 480 * j * 4;
		for (i = 0; i < length; i++)
		{
			p3  = p2 - 4*i;
			*(p3++) = blue;
			*(p3++) = green;
			*p3 = red;
		}
	}
}

void lcd_show_bmp(int x, int y, int length, int height, char* buf)
{
	char *p1;
	char *p2;
	char *p3;
	int i, j;
	x = 479 - x;
	y = 271 - y;
	p1 = fbp + x*4 + 480 * y * 4;
	for (j = 0; j < height; j++) {
		p2 = p1 - 480 * j * 4;
		for (i = 0; i < length; i++)
		{
			p3  = p2 - 4*i;
			*(p3++) = *(buf++);
			*(p3++) = *(buf++);
			*p3 = *(buf++);
		}
	}
}

void lcd_close()
{
	/*释放缓冲区，关闭设备*/
	munmap(fbp, screensize);

	close(fbfd);
}
