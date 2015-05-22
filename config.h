//Configuration File .h


//Phant configuration
#define ServerIP "24.237.235.227:81" //The Phant server's IP address and port

#define ServerIP_commas 24,237,235,227 //The IP address without port, or standard formating Used for Ethernet.Connect

#define PhantMag_PublicKey "zDX2oGWagqf0XQGgyWdBcW5O910A" //The Magnetometer Public Key
	#define PhantMag_PrivateKey "E8v4LWNOb7f9Rg7ewk1nFLNd7nrG" // The Magnetometer Private Key

#define PhantHealth_PublicKey "zQKK1KbjbeT0XQGgyWdBcW5O910A" //The Platform Health Public Key
	#define PhantHealth_PrivateKey "EDKKQKkBkGI9Rg7ewk1nFLNd7nrG" // The Platform Health Private Key



//Ethernet configuration
#define BackupIP 192, 168, 1, 177 //Backup IP address if DHCP fails

#define MacAddress 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED //Mac address of Ethernet



//Temperature and humidity sensor config
#define DHTPINMAG 2 //Pin of Magnetometer Sensor

#define DHTPINMAIN 3 //Pin of Main Sensor

#define DHTTYPE DHT22 //Type of sensor

//Sensor Intervals Config
//These intervals Do not matter, they are simply how often the sensor is queried
#define Tempeature_Humidity 20000 //value in ms, no longer than 30000 it has to fit into an int

#define GPSint 10000

//These intervals Do matter, they are how often data is reported
#define intervalMagnetometer 50

#define interHealth 30000
//Other time based values
#define failures 30 //how many times it can fail, before reseting


#define GPSECHO true;

#define PHANTECHO true;
