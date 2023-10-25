# BMET2992-MajorProject
Device Name: PPG-PulseGlow

# Code structure:

## ESP code:
Major_project.ino (upload this to ESP32)

### Modules:
- Scheduler:
- Switch:
- LED: [need to change it into individual class]
- BTComm: [need to change it into individual class]

## GUI code:
- GUI.py: run to create GUI
- serialcomm.py: 
    class SerialReader
- visualAlarm.py:
    create_led()
    set_led_color()

[to do:]

- LED switching color logic integrated with event controls
- receive data from BT in ESP32 [optional]
    needed to stop measuring

- patientInfo.py: [extra feature]
    class PatientInfo
        _id // unique id of the patient
        _name // optional
        _age // optional
        _csv_file_path // a csv file to store the received sensor_data
        _log_file_path // a txt file to store all actions in GUI relate to that patient
        _report_path // a txt file to store all other patient info

        latest_pulse_rate
        avg_pulse_rate
        latest_RR
        avg_RR
        pulse_rate_FFT
        warning_msg
- signalProc.py
    class SignalProc
        _sensor_data
        _sensor_data_dc_removed
        _peaks
        _RR
        _latest_pulse_rate
        _avg_pulse_rate

        fig, ax = plot_pulse_rate(fig, ax)
        fig, ax = plot_wave(fig, ax)
        fig, ax = plot_FFT(fig, ax)
        fig, ax = plot_peaks(fig, ax)


- test data transfer from BT to signal processing mod