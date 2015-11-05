#ifndef BMP180DEV3_H_INCLUDED
#define BMP180DEV3_INCLUDED

#define sleepms(ms)  usleep((ms)*1000)

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <math.h>

// BMP085 & BMP180 Specific code
#define BMPx8x_I2CADDR           0x77
#define BMPx8x_CtrlMeas          0xF4
#define BMPx8x_TempConversion    0x2E
#define BMPx8x_PresConversion0   0x34
#define BMPx8x_Results           0xF6
#define BMPx8x_minDelay          4     //require 4.5ms *1000/700 'turbo mode fix'= 6.4-Retry =4.4
#define BMPx8x_RetryDelay        2     //min delay for temp 4+2=6ms, max 4+2*20=44ms for pressure
                                       //Will stop waiting if conversion is complete

const unsigned char BMPx8x_OverSampling = 3;

int      bmp_ReadInt          (int fd, uint8_t *devValues,uint8_t startReg,uint8_t bytesToRead);
int      bmp_WriteCmd         (int fd, uint8_t devAction);
int      bmp_Calibration      (int fd);
int      WaitForConversion    (int fd);
int      bmp_GetPressure      (int fd, double *Pres);
int      bmp_GetTemperature   (int fd, double *Temp);
int		 Use				  ();

double   bmp_altitude         (double p);
double   bmp_qnh              (double p,double StationAlt);
double   ppl_DensityAlt       (double PAlt,double Temp);

#endif
