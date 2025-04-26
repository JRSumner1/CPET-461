# CPET-461 — Real-Time Operating Systems (Spring 2025)

Hands-on FreeRTOS labs for the **CPET-461 Real-Time Operating Systems** course at RIT.  
All projects target the **STM32 Nucleo-L476RG** board and are developed in **STM32CubeIDE 1.17.0**.

---

## Table of Contents
1. [Hardware](#hardware)
2. [Software / Toolchain](#software--toolchain)
3. [Repo Layout](#repo-layout)
4. [Lab Summaries](#lab-summaries)
5. [Building & Flashing](#building--flashing)
6. [Contributing](#contributing)

---

## Hardware
| Part | Purpose |
|------|---------|
| **STM32 Nucleo-L476RG** | Cortex-M4 MCU + ST-Link |
| **Solderless breadboard + LEDs** | External indicators for RTOS tasks |
| **HC-SR04 ultrasonic sensor** | Distance measurement (Lab 6) |

---

## Software / Toolchain
* **STM32CubeIDE 1.17.0** – GCC 12 + CubeMX generator  
* **PuTTY / TeraTerm** – UART console (9600 8-N-1)  
* (Optional) **VS Code** + C/C++ & Cortex-Debug extensions for source browsing

---

## Repo Layout
```bash
CPET-461/
│   .gitignore
│   README.md
│
├───Lab1
│   ├───Core
│   │   ├───Inc
│   │   │   └───main.h
│   │   └───src
│   │       ├───freertos.c
│   │       └───main.c
│   ├───Lab1.ioc
│   └───Lab1.pdf
│
├───Lab2
├───Lab3
├───Lab4
├───Lab5
├───Lab6
└───Lab7
```
---

## Lab Summaries
| Lab | Theme & Key Skills | One-liner |
|---|-------|-----------|
| **1 – Hello RTOS** | CubeIDE setup, create a FreeRTOS task, blink LD2. | Single LED heartbeat |
| **2 – Pre-emptive Scheduling** | Compare HAL_Delay vs osDelay; priority inversion. | Two LEDs concurrent |
| **3 – Resource Sharing** | UART printing from 3 tasks with/without mutex. | Corrupted vs clean rows |
| **4 – Simple Monitor** | Encapsulated mutex monitor pattern; modular code. | Buffered UART prints |
| **5 – Unilateral Sync** | EXTI button ISR ➜ signal flags → semaphore refactor. | LED flash on button |
| **6 – Timer Applications** | TIM8 input-capture + TIM16 PWM; HC-SR04 ranging. | Distance over UART |
| **7 – Timer-Generated ISRs** | 10 Hz TIM16 interrupt, auto-stop, concurrent LED tasks. | 3 blinking LEDs |

---

## Building & Programming
1. **Clone**
   ```bash
   git clone https://github.com/JRSumner1/CPET-461.git
   cd CPET-561
   ```
2. **Open** STM32CubeIDE ➜ File → Open Projects from File System… ➜ select repo root. CubeIDE detects every *.project.
3. Select a lab ➜ **Build** (hammer icon).
4. **Debug** (green bug icon) – LD2 starts blinking when the scheduler runs.