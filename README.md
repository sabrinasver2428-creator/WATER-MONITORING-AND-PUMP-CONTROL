# 💧 Water Level Monitoring and Pump Control System

This project is a *microproject* developed as part of the *S3 Electronics and Computer Engineering* course at *Saintgits College of Engineering*.  
It aims to design an *automatic water level monitoring and pump control system* using an *ESP8266 (NodeMCU)* and an *ultrasonic sensor* to prevent water wastage and pump dry-run conditions.

---

## 🧠 Project Overview

Manual control of water pumps often leads to problems such as *tank overflow, **underflow, and **unnecessary power usage*.  
This project provides a smart solution by automatically monitoring water levels and controlling the pump accordingly.

The system:
- Monitors the water level in an overhead tank using an *ultrasonic sensor*
- Automatically turns the *pump ON* when the level is *LOW*
- Turns *pump OFF* when the tank is *FULL*
- Protects the pump from *dry-run* operation

---

## ⚙ Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP8266 (NodeMCU) | 1 | Microcontroller board |
| Ultrasonic Sensor (HC-SR04) | 1 | Measures tank water level |
| Relay Module | 1 | Controls the water pump |
| Water Pump | 1 | DC/AC motor pump |
| Jumper Wires | - | For circuit connections |
| Power Supply | 1 | 5V or USB power |

---

## 🔌 Circuit Connections

| Ultrasonic Sensor | NodeMCU Pin |
|--------------------|-------------|
| VCC | VIN (5V) |
| GND | GND |
| TRIG | D5 |
| ECHO | D6 |

| Relay Module | NodeMCU Pin |
|---------------|-------------|
| VCC | 3.3V / 5V |
| GND | GND |
| IN | D4 |

---

## 📊 Working Principle

1. The *ultrasonic sensor* continuously measures the distance from the sensor to the water surface.  
2. Based on the distance, the *ESP8266* determines whether the tank is full, mid, or low.  
3. If the level is *low, the **relay activates* and turns ON the pump.  
4. When the level reaches *full, the **relay deactivates*, turning OFF the pump.  
5. This ensures optimal use of water and electricity.

---

## 💻 Code

The complete source code is provided in the file:  
[water_leveloriginal.ino](./water_leveloriginal.ino)

Upload the code to your *NodeMCU* using the *Arduino IDE* after connecting all components as per the circuit.

---

## 🖼 Block Diagram

Include your block diagram in the repository under:![WhatsApp Image 2025-10-20 at 11 51 24_b482773c](https://github.com/user-attachments/assets/35abb27c-f9de-4baf-8514-a08d2d23c263)


Then reference it like this:

![Circuit Diagram](images/cir![WhatsApp Image 2025-10-17 at 11 13 14_faf3cc6a](https://github.com/user-attachments/assets/2956c143-a51a-4107-9ab9-15eaec6f1147)
cuit_diagram.png)

---

## 🎥 Demonstration Video

Upload your project demo video to *Google Drive, **YouTube, or **GitHub Releases*, and link it below:

🔗 [Watch Demonstration Video](https://example.com/demo-link)

https://github.com/user-attachments/assets/f8850120-5e4e-49c2-80c0-c7d769cc3029



(Replace with your actual video link)

---

## 📄 Project Report

[WATER_LEVEL_MONITORING_MICROPROJECT (4).pdf](https://github.com/user-attachments/files/22998981/WATER_LEVEL_MONITORING_MICROPROJECT.4.pdf)



---

## 🚀 Future Enhancements

- Add *IoT-based monitoring (Blynk / ThingSpeak)*  
- Include *buzzer alerts* for dry-run or overflow  
- Add a *manual/auto switch* for flexibility  
- Integrate *battery backup* for uninterrupted control  


## 👩‍💻 Author

*Sabrina Susan Varghese*  
S3 Electronics and Computer Engineering  
Batch 2024–2028  
*Saintgits College of Engineering*


## 📷 Project Setup

You can include your setup image here for visual reference:

![Project Setup](images/project_setup.jpg)
