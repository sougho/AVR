/* 
 * File:   usb.h
 * Author: ramtaru
 *
 * Created on August 31, 2014, 6:48 PM
 */

#ifndef USB_H
#define	USB_H

#ifdef	__cplusplus
extern "C" {
#endif


void usb_init();


typedef struct BDn {
    unsigned char STAT;
    unsigned char CNT;
    unsigned char ADRL;
    unsigned char ADRH;
} BDn_type;




typedef struct setupPkg {
    unsigned char bmRequestType;
    unsigned char bRequest;
    unsigned char wValueL;
    unsigned char wValueH;
    unsigned char wIndexL;
    unsigned char wIndexH;
    unsigned char wLengthL;
    unsigned char wLengthH;
} setupPkg_type;



/*********************/
/* Device Descriptor */
/*********************/
typedef struct deviceDescriptor {
    unsigned char  bLength;            //size of descriptor in bytes
    unsigned char  bDescriptorType;    //device descriptor code
    unsigned short bcdUSB;             //USB 2.0
    unsigned char  bDeviceClass;       //class code
    unsigned char  bDeviceSubClass;    //sub-class code
    unsigned char  bDeviceProtocol;    //protocol code
    unsigned char  bMaxPacketSize;     //Max packet size
    unsigned short idVendor;           //Vendor ID (lsb)
    unsigned short idProduct;          //Product ID (lsb)
    unsigned short bcdDevice;          //release ID (lsb)
    unsigned char  iManufacturer;      //Vendor string descriptors
    unsigned char  iProduct;           //Product string descriptors
    unsigned char  iSerialNumber;      //Serial string descriptors
    unsigned char  bNumConfigurations; //num configurations
} deviceDescriptor_type;


/****************************/
/* Configuration Descriptor */
/****************************/
typedef struct configurationDescriptor {
    unsigned char  bLength;             // size of descriptor in bytes
    unsigned char  bDescriptorType;     // config descriptor code
    unsigned short wTotalLength;        // config+interface+endpoint descriptors
    unsigned char  bNumInterfaces;      // Number of interfaces
    unsigned char  bConfigurationValue; // Value to select this interface
    unsigned char  iConfiguration;      // Index of string descriptor
    unsigned char  bmAttributes;        // Powered (self or hub)
    unsigned char  bMaxPower;           // Power usage
} configurationDescriptor_type;



/************************/
/* Interface Descriptor */
/************************/
typedef struct interfaceDescriptor {
    unsigned char bLength;            // size of descriptor in bytes
    unsigned char bDescriptorType;    // interface descriptor code
    unsigned char bInterfaceNumber;   // Number of interfaces
    unsigned char bAlternateSetting;  // Value to select alt interface
    unsigned char bNumEndpoints;      // Num endpoints used
    unsigned char bInterfaceClass;    // Class code
    unsigned char bInterfaceSubClass; // Subclass code
    unsigned char bInterfaceProtocol; // Protocol code
    unsigned char iInterface;         // Index of String Descriptor
} interfaceDescriptor_type;



/***********************/
/* Endpoint Descriptor */
/***********************/
typedef struct endpointDescriptor {
    unsigned char  bLength;          // size of descriptor in bytes
    unsigned char  bDescriptorType;  // endpoint descriptor type
    unsigned char  bEndpointAddress; // endpoint bitmap
    unsigned char  bmAttributes;     // attributes bitmap
    unsigned short wMaxPacketSize;   // max packet size
    unsigned char  bInterval;        // polling interval (ignored for control)
} endpointDescriptor_type;



/**********************/
/* String Descriptor0 */
/**********************/
typedef struct stringDescriptor0 {
    unsigned char  bLength;
    unsigned char  bDescriptorType;
    unsigned short wLANGID;
} stringDescriptor0_type;



/**********************/
/* String Descriptors */
/**********************/
typedef struct stringDescriptorN {
    unsigned char  bLength;
    unsigned char  bDescriptorType;
    unsigned short str[10];
} stringDescriptorN_type;


/*************************/
/* Generic 8 byte packet */
/*************************/
typedef struct pkg {
    unsigned char BYTE0;
    unsigned char BYTE1;
    unsigned char BYTE2;
    unsigned char BYTE3;
    unsigned char BYTE4;
    unsigned char BYTE5;
    unsigned char BYTE6;
    unsigned char BYTE7;
} pkg_type;

/*
 * Structure Instances at specific memory
 */
BDn_type  BD0_OUT @ 0x0400;
BDn_type  BD0_IN @ 0x404;
BDn_type  BD1_OUT @ 0x408;
setupPkg_type hostSetupPkg @ 0x428;
deviceDescriptor_type devDescr @ 0x430;
configurationDescriptor_type configDescr @ 0x442;
interfaceDescriptor_type interfDescr @ 0x44B;
endpointDescriptor_type endpoint1DescrOUT @ 0x454;
stringDescriptor0_type stringDescr0 @ 0x470;
stringDescriptorN_type  stringDescr1 @ 0x474;
stringDescriptorN_type  stringDescr2 @ 0x48A;
pkg_type outPkgEp1 @ 0x4A0 = {0,0,0,0,0,0,0,0};

/**/
/***********/
/* Globals */
/***********/
unsigned char UOWN  = 0x80;
unsigned char DTS   = 0x40;
unsigned char DTSEN = 0x08;
unsigned char OUT_TOKEN   = 0x01;
unsigned char SETUP_TOKEN = 0x0D;
unsigned char IN_TOKEN    = 0x09;
unsigned char descriptorType_device = 0x01;
unsigned char descriptorType_config = 0x02;
unsigned char descriptorType_string = 0x03;




#ifdef	__cplusplus
}
#endif

#endif	/* USB_H */

