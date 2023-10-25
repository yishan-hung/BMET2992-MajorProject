import PySimpleGUI as sg

def create_led(canvas, x1, y1, x2, y2, color):
    return canvas.TKCanvas.create_oval(x1, y1, x2, y2, fill=color)

def set_led_color(window, led_key, led_id, color):
    canvas = window[led_key]
    canvas.TKCanvas.itemconfig(led_id, fill=color)

# layout = [
#     [sg.Canvas(size=(150, 150), background_color='white', key='led1')],
#     [sg.Text('Change circle color to:'), sg.Button('Red'), sg.Button('Blue')]
# ]

# window = sg.Window('LED Indicator using Canvas', layout, finalize=True)

# # Initially create the LED with red color
# led_id = create_led(window['led1'], 50, 50, 100, 100, 'red')

# while True:
#     event, values = window.read()
#     if event == sg.WIN_CLOSED:
#         break
#     if event in ('Blue', 'Red'):
#         set_led_color(window, 'led1', led_id, event)
