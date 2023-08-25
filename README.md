# Biologically Inspired Perching Drone
This project aims to develop an effective attachable modular device for enabling drones to perch on cyclindrical objects, while maintaining the ability to land on flat surfaces. It was originally inspired by the claws of birds of prey and their unique biological ratcheting mechanism that allows them to tightly and securely grip with their talons without relying entirely on muscular strength.

By using 3D printing manufacturing and easy to find off-the-shelf parts we hope to provide a design that is accessible and easily implemented into different drones. Additionally, we hope to make it easy for others to contribute their ideas, modifications, and remixes of original designs.

Currently, only a single preliminary version has been released, which offers effective perching for 5-inch drones that can be manually triggered by a pilot via BetaFlight firmware. Although this is a good first-step/proof-of-concept, the idea has far more potential. Further iterations could offer support to more drones of different sizes and software that functions together with autopilot firmware (e.g., Ardupilot) would allow for full automation.

## Table of Contents
1. Directory Structure
2. Getting Started
   1. 3D Printing
   2. Hardware Assembly
   3. Electronics Assembly
   4. Software
4. How to Use
   1. Setting Up BetaFlight
   2. Connect ELRS controller
   3. Actuate Switch
6. Credits
7. Licences
8. How to Contribute

The files within the project contain both the hardware and software required to build a claw attachment for a drone.

## Directory Structure
* [control_code/](./biologically-inspired-perching-drone/claw_control)  - folder containing pico firmware
  * [include/](./biologically-inspired-perching-drone/claw_control/include)
  * [lib/](./biologically-inspired-perching-drone/claw_control/lib)
  * [src/](./biologically-inspired-perching-drone/claw_control/src)
  * [test/](./biologically-inspired-perching-drone/claw_control/test)
  * [platformio.ini](./biologically-inspired-perching-drone/claw_control/platformio.ini)
* [hardware/](./biologically-inspired-perching-drone/hardware)          - folder containing hardware (both electronics & CAD)
* [README.md](./biologically-inspired-perching-drone/README.md)

## Getting Started
To get started with constructing the modular perching attachment for drones ensure you have the following components, links (UK purchasers) have been provided to the exact components used in our version of the build:
#### Claw
* [3D Printer](https://www.crealityofficial.co.uk/products/official-creality-ender-3-3d-printer?gclid=CjwKCAjw5_GmBhBIEiwA5QSMxMXDsvX_tW-ISPtKeVc1NaB69DFpaEF8qKHRZwr1OY2PAPOxLsnU4xoC1LYQAvD_BwE)
* [PLA Filament](https://www.amazon.co.uk/s?k=pla+filament&adgrpid=78891941511&hvadid=606046905090&hvdev=c&hvlocphy=9045801&hvnetw=g&hvqmt=e&hvrand=5819192572464950726&hvtargid=kwd-29312074397&hydadcr=13760_2300773&tag=googhydr-21&ref=pd_sl_1zij8bcx5k_e)
* [4x OD12mm, ID8mm Bearings](https://simplybearings.co.uk/shop/p2772/Budget-MR1282Z-Metal-Shielded-Deep-Groove-Ball-Bearing-8x12x3.5mm/product_info.html)
* [4x 25mm M3 Screws](https://www.accu.co.uk/cap-head-screws/2804-SSC-M3-25-A2?uk_google_shopping=1&c=3&gclid=CjwKCAjwivemBhBhEiwAJxNWN9nE6UgO0qUt18KDeclZdjt5iMfUIQenEBjWHBwZsNzfqwtM-vBovRoC3A4QAvD_BwE)
* [2x M1.5 Self-tapping Screws](https://cpc.farnell.com/neutrik/a-screw-1-8/screws-for-d-mounts-a-type/dp/AV18050?mckv=s_dc|pcrid|426684131039|kword||match||plid||slid||product|AV18050|pgrid|100371158878|ptaid|pla-1869734976461|&CMP=KNC-GUK-CPC-SHOPPING-9262013734-100371158878-AV18050&s_kwcid=AL!5616!3!426684131039!!!network}!1869734976461!&gclid=CjwKCAjwivemBhBhEiwAJxNWN8YT4Eb2GvifQI9ZS6wh_OzB7m4AdSvY-hiyPY48TIBvsaB6Vbc0dBoCt_0QAvD_BwE)
* [Sand Paper 120 Grit (lower grit works better)](https://www.amazon.co.uk/s?k=sandpaper&crid=HUOTKIT8XZ5P&sprefix=sandpap%2Caps%2C128&ref=nb_sb_noss_2)
* [Super Glue](https://www.amazon.co.uk/Gorilla-4044205-Superglue-15g/dp/B003CT4XT0/ref=sxts_rp_s_1_0?content-id=amzn1.sym.07198d44-a16f-4503-b71e-3f4c67470a0f%3Aamzn1.sym.07198d44-a16f-4503-b71e-3f4c67470a0f&crid=3U46AON4XNTIE&cv_ct_cx=super%2Bglue&keywords=super%2Bglue&pd_rd_i=B003CT4XT0&pd_rd_r=47f26ec3-a199-42ab-9789-1182f3514e07&pd_rd_w=P5udf&pd_rd_wg=kLEzL&pf_rd_p=07198d44-a16f-4503-b71e-3f4c67470a0f&pf_rd_r=HG953RS7NASVVNRHSK70&qid=1692183417&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=super%2Bglu%2Caps%2C127&sr=1-1-1890b328-3a40-4864-baa0-a8eddba1bf6a&th=1)
* [Raspberry Pi Pico](https://thepihut.com/products/raspberry-pi-pico)
* [Metal-Geared DC Motor 298:1](https://thepihut.com/products/micro-metal-gearmotor?variant=35654648273&currency=GBP&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=Cj0KCQiA6fafBhC1ARIsAIJjL8mLdStrBHD3Pgv4j3L-IIv1ZZDEiXFt3Oo2TUNnxJZUXy6bFfqBKtkaAjwJEALw_wcB)
* [22AWG Black, Red, and White Wire](https://www.amazon.co.uk/TUOFENG-Electric-Flexible-Different-Electronic/dp/B07G72DRKC/ref=sr_1_1_sspa?crid=3U9S56MR5OMVS&keywords=22awg%2Bsilicone%2Bwire&qid=1692281205&sprefix=22AW%2Caps%2C161&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1)
* [L9110H H-Bridge](https://thepihut.com/products/l9110h-h-bridge-motor-driver-for-dc-motors-8-dip?variant=39823794634947)
* [10Ω Resistor](https://thepihut.com/products/resistor-packs?variant=37986550481091&currency=GBP&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=CjwKCAjwivemBhBhEiwAJxNWN_s7JJdB-hqIBEtf6_qF9BAwgs8ZXRBKjHlvWR9Kjt12iqXppCH54xoCAaQQAvD_BwE)
* [Strip Board](https://thepihut.com/products/universal-proto-board-pcbs-4cm-x-6cm-3-pack)

#### Drone
Here is a list of the components we used in the construction of test drone in case you would like directly replicate the build, however this project can be easily adapted to any drone flight controller:
* [SpeedyBee F405V3 Flight Controller + ESC Stack](https://www.unmannedtechshop.co.uk/product/speedybee-f405-v3-bls-50a-4in1-flight-stack/?gclid=CjwKCAjwivemBhBhEiwAJxNWN6jE5y21ktbdwFi6sgO14pVqPU7F3PHDaCu1INcH72N3wYPJjWJN5hoCyHEQAvD_BwE)
* [Motors](https://cheapdrone.co.uk/dys-sun-fun-sf2207-2207-2400kv-2750kv-4-5s-brushless-motor-cw-thread-for-rc-drone-fpv-racing-drone-parts)
* [BetaFlight ELRS Reciever](https://www.unmannedtechshop.co.uk/product/betafpv-elrs-lite-receiver-2-4ghz-flat-antenna/)
* [TBS Open Source Drone Frame](https://www.quadcopters.co.uk/tbs-source-one/tbs-source-two-racing-frame-v01)
* [LiPo](https://www.amazon.co.uk/GOLDBAT-Battery-Airplane-Quadcopter-Helicopter/dp/B0BVZDYGQ8/ref=sr_1_5?keywords=3s+2200mah+lipo&qid=1692314138&sprefix=3S+2%2Caps%2C117&sr=8-5)

### 3D Printing
To 3D print the mechanicals parts for the perching claw, you need to download the relevant STL files from the link below:

When printing components with gears ensure that the layers of the print are parallel to the direction of force transmission from the gear to reduce the risk of gears shearing (see below). The design is fully finctional with 100% in-fill PLA, however, can be made more robust using PETG or ABS filaments.

If you wish to remix the hardware designs, the SolidPart files can also be found from the link above and consider submitting the modified design as a remix so that others can easily find custom designs that may be useful for them.

### Hardware Assembly
1. After printing cut out and attach sandpaper to the inside of the claw with superglue to provide a high friction surface for the gripper.
2. Attach the metal-geared DC motor to the side mount of your choice and screw in place with the 1.5mm self tapping screws.
3. After the motor is attached, press-fit the bearings into each of the cut-outs in the side mounts.
4. Press fit the claw onto the motor and bearings, ensure that when the two claw part gears mesh that the claws themselves are parallel with each other.
5. Press fit M3 nuts into the cut-outs on the top mount.
6. Attach and super-glue the top mount to the side mounts with claws attached by inserting the side mount tabs into the top mount.
7. Attach the gripper to the drone by threading the 25mm M3 screws through the flight controller mount and the drone frame, screw them into the nuts of 3D-printed top mount until the FC and the gripper are firmly attached to the drone frame. (Do not overtighten as this can cause damage to your FC!)

This concludes the hardware assembly of this project, next we move onto the electronics and finally conclude with the software.

### Electronics Assembly
We recommend to first layout the circuit on a breadboard (see picture below) and perform a test to ensure all your components are functional before soldering them to a prototyping board.

## Hardware
In this folder you can find STL files that can be downloaded for 3D printing and the original parameterised SolidWorks CAD files and assemblies that can be modified to customise/remix the design to suit different drone and hardware configurations. 
* [Bivalve_7_talon/](./biologically-inspired-perching-drone/hardware/Bivalve_7_talon) - folder containing the Solidworks part files and STL files for a version of the bivalve claw mechanism with additional claws (3-4 config).
* [Bivalve_Claw_Mechanism/](./biologically-inspired-perching-drone/hardware/Bivalve_Claw_Mechanism) - folder containing the SolidWorks part files, STL files, and assembly for the bivalve claw mechanism design.
* [Tendon_Arm/](./biologically-inspired-perching-drone/hardware/Tendon_Arm) - folder contianing the STL files used during the testing and development of the tendon claw design.


## Drone Image
![drone_perching](./images/drone_perching.jpeg)

## Licenses
Hardware (all files stored under the [hardware](./biologically-inspired-perching-drone/hardware) folder) are under the Creative Commons Attribution-ShareAlike 4.0 International license.

Firmware (all files stored under the [claw_control](./biologically-inspired-perching-drone/claw_control) folder) are under the MIT license.

See each folders LICENSE.txt file for details.
