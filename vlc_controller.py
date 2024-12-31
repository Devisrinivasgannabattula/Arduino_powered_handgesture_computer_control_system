import serial
import pyautogui
import time

# Set up serial communication
try:
    ser = serial.Serial('COM3', 9600)
    time.sleep(5)  # Wait for the serial connection to initialize
    
    while True:
        if ser.in_waiting > 0:
            try:
                command = ser.readline().decode().strip()
                
                if command == "VOL_UP":
                    pyautogui.press('volumeup')
                elif command == "VOL_DOWN":
                    pyautogui.press('volumedown')
                elif command == "PLAY_PAUSE":
                    pyautogui.press('space')  # VLC typically uses 'space' for play/pause
                    
            except UnicodeDecodeError:
                print("Error decoding the data received from Arduino.")
            
except serial.SerialException as e:
    print(f"Serial error: {e}")

finally:
    ser.close()