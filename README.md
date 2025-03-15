AI Controlled Gesture Recognition Robotic Hand

Running on Laptop

1. Installation:

VSCode and Python: Download and install the latest versions of Visual Studio Code (VSCode) and Python on your laptop.

2. Setting up Environment:

- Project Folder Creation: Create a project folder for your code.

- Virtual Environment: Open the terminal and type the following command to create a virtual environment:

python -m venv .venv

3. Installing Required Libraries:

- CVZone: Install CVZone library using pip:

pip install cvzone

- MediaPipe: Install MediaPipe library using pip:

pip install mediapipe

- PySerial: Install PySerial library using pip:

pip install pyserial

4. Running the Code:

- Copy the laptop code into the virtual environment folder.

- Run the code from within the virtual environment.


Running on Raspberry Pi

1. Preparation:

Laptop Hotspot Setup: Create a hotspot on your laptop with VNC Viewer installed.
SSID: Hand
Password: 123456789

2. Raspberry Pi Setup:

- Powering Up: Power on the Raspberry Pi and wait for it to connect to the laptop hotspot.

3. Connecting via VNC Viewer:

- Copy the IP address of the Raspberry Pi after it has connected to the laptop hotspot.

- Open VNC Viewer, create a new connection, and paste the Raspberry Pi's IP address in the connection settings.

4. Raspberry Pi Credentials:

- Username: pi
- Password: pi

5. Running the Code:

- Navigate to the Documents folder on the Raspberry Pi.

- Run the provided code.

Note: Due to RAM constraints, there might be a slight delay in image processing.
