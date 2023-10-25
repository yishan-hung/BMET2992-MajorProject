import PySimpleGUI as sg

def create_led(canvas, x1, y1, x2, y2, color):
    return canvas.TKCanvas.create_oval(x1, y1, x2, y2, fill=color)

def set_led_color(window, led_key, led_id, color):
    canvas = window[led_key]
    canvas.TKCanvas.itemconfig(led_id, fill=color)


# # [Import Annie's code]
# # changes the visual alarm color !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# # need to first import BPM values!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!:
# if 0 <= BPM <= 50: # also need to add status to system log? low pulse
#     button1_color = ('red')
#     button2_color = ('grey')
#     button3_color = ('grey')
# elif 100 <= BPM <= 160: # high pulse
#     button1_color = ("grey")
#     button2_color = ("red")
#     button3_color = ("grey")
# elif BPM < 0 or BPM > 160: # poor recording
#     button1_color = ("grey")
#     button2_color = ("grey")
#     button3_color = ("red")
# else: # normal pulse
#     button1_color = ("grey")
#     button2_color = ("grey")
#     button3_color = ("grey")
