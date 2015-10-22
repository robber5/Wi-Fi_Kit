#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"
#include "arduinostyle.h"
#include "user_interface.h"
#include "wifi.c"
//#define STATION_MODE		0x01

//Main Timer
static volatile os_timer_t main_timer;

void loop(void *arg) 
{
	char c;
	while (Serial.available() > 0) 
	{
		c = (char) Serial.read();
		Serial.write(c);
	}
}

void CMD(char *s)
{
	os_printf(s);
}


void start(void) 
{
	// And this is used to print some information once the device is initialized
	os_printf("Hello, world!\n");

	//Disarm timer
	//os_timer_disarm(&main_timer);

	//Setup timer
	//os_timer_setfn(&main_timer, (os_timer_func_t *) loop, NULL);

	//Arm the timer
	//&main_timer is the pointer
	//1000 is the fire time in ms
	//0 for once and 1 for repeating
	//os_timer_arm(&main_timer, 1000, 1);


	wifi_scan_ap();

os_delay_us(65535);
wifi_scan_ap();
	/*
	if(!wifi_station_scan(NULL, scan_done))
	{
		os_printf("WIFI scan failed!\n");
	}


	os_printf("Done!");
	*/
}



/*
 * user_init should be used mainly for initialization
 */
void user_init() 
{
	// This is used to setup the serial communication
	Serial.begin(115200);


	// once the initialization is done we can start with our code
	os_delay_us(65535);

	system_init_done_cb(start);
}
