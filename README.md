# PowerTrailer
Firmware and hardware for battery SOC and generator control

## Hardware
- Heltec Wireless Stick for control, comms, and data display
- INA226 x 3 for monitoring of
    - solar in
    - in/out from/to inverter-charger
    - DC loads
- 2x buttons for local control / navidation
- input from inverter/charger generator start command
- relay for dry-contact closure generator start command
- 24V nom --> 5V buck for 5V system power
- terminals for connection of external inputs

## Firmware
- using RTOS
- ESP32-s3 (Heltec Wireless Stick) arduino framework
- NVRam for storage of:
  - settings
  - SOC

### Tasks
1. System Control
   - System coordination actions
   - take inputs on queue from LORA. buttons, INA, and coordinate actions
     > LORA - gen start from remote
     > LORA - System Setting Change
     > BUTTON - pressed Short
     > BUTTON - pressed Long
     > BUTTON - doiuble pressed
     > INA - New Data
   - format outgoing LORA message packets
   - translate incoming LORA message packets
2. button monitoring
3. INA polling
   - interval?
   - Kalman filter
   - calculation of means (V, I, W) for individual shunts, and net
     - 1s
     - 5s
     - 1m
     - 5m
     - 60m
     - 24h
   - calculation of SOC
   - Stored at ??min intervals??
   - send data to System Control task for transmission/display
4. Display Task
   - receive messages from system control task for display
   - cycle through display values from system control
 5. LORA Task
   - Take data sent from system task and transmit
   - receive data and send to sysstem task
