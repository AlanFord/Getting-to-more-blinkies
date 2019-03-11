EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:beagleboneBlack-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R_Small R101
U 1 1 5C86990B
P 5970 3795
F 0 "R101" V 6055 3715 50  0000 L CNN
F 1 "220R" V 5890 3710 50  0000 L CNN
F 2 "" H 5970 3795 50  0001 C CNN
F 3 "" H 5970 3795 50  0001 C CNN
	1    5970 3795
	0    1    1    0   
$EndComp
$Comp
L BS170 Q101
U 1 1 5C869B59
P 5180 3695
F 0 "Q101" V 5500 3625 50  0000 L CNN
F 1 "BS270" V 5415 3590 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 5380 3620 50  0001 L CIN
F 3 "" H 5180 3695 50  0001 L CNN
	1    5180 3695
	0    1    1    0   
$EndComp
$Comp
L LED D101
U 1 1 5C869C29
P 5665 3795
F 0 "D101" H 5665 3895 50  0000 C CNN
F 1 "LED" H 5665 3695 50  0000 C CNN
F 2 "" H 5665 3795 50  0001 C CNN
F 3 "" H 5665 3795 50  0001 C CNN
	1    5665 3795
	1    0    0    1   
$EndComp
Wire Wire Line
	5380 3795 5515 3795
Wire Wire Line
	5815 3795 5870 3795
$Comp
L +5V #PWR102
U 1 1 5C869E81
P 6210 3750
F 0 "#PWR102" H 6210 3600 50  0001 C CNN
F 1 "+5V" H 6210 3890 50  0000 C CNN
F 2 "" H 6210 3750 50  0001 C CNN
F 3 "" H 6210 3750 50  0001 C CNN
	1    6210 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR101
U 1 1 5C869EA7
P 4860 3815
F 0 "#PWR101" H 4860 3565 50  0001 C CNN
F 1 "GND" H 4860 3665 50  0000 C CNN
F 2 "" H 4860 3815 50  0001 C CNN
F 3 "" H 4860 3815 50  0001 C CNN
	1    4860 3815
	1    0    0    -1  
$EndComp
Wire Wire Line
	6210 3750 6210 3795
Wire Wire Line
	6210 3795 6070 3795
Wire Wire Line
	4980 3795 4860 3795
Wire Wire Line
	4860 3795 4860 3815
Text GLabel 5275 3400 2    60   Input ~ 0
23-GPIO1_17
Wire Wire Line
	5275 3400 5180 3400
Wire Wire Line
	5180 3400 5180 3495
$EndSCHEMATC
