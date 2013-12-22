# An excercise for Python coding.
# Using Tkinter to get user inputs, and save to an XML file using etree module
# by Weichsel
# date: 2013.12.14

import Tkinter as GUI
import tkMessageBox
from xml.etree import ElementTree as ET

class App:
    _file_name = ''

    def __init__(self, master):
        self.CreateGui(master)        
    
    def CreateGui(self, root):
        # toolbar
        frame_button = GUI.Frame(root)
        
        button_new = GUI.Button(frame_button, text = "New", width = 8, command = self.CmdNew)
        button_new.pack(side = GUI.LEFT)
        
        button_save = GUI.Button(frame_button, text = "Save", width = 8, command = self.CmdSave)
        button_save.pack(side = GUI.LEFT)
        
        frame_button.pack(side = GUI.TOP)

        # name 
        frame_name = GUI.Frame(root)
        
        label_name = GUI.Label(frame_name, text = 'name', anchor = GUI.E, width = 10)
        label_name.pack(side = GUI.LEFT)

        self.entry_name = GUI.Entry(frame_name, width = 20)
        self.entry_name.pack(side = GUI.LEFT)

        frame_name.pack(side = GUI.TOP)

        # phone 
        frame_phone = GUI.Frame(root)
        
        label_phone = GUI.Label(frame_phone, text = 'phone', anchor = GUI.E, width = 10)
        label_phone.pack(side = GUI.LEFT)

        self.entry_phone = GUI.Entry(frame_phone, width = 20)
        self.entry_phone.pack(side = GUI.LEFT)

        frame_phone.pack(side = GUI.TOP)     

    def CmdNew(self):
        self.entry_phone.delete(0, GUI.END)
        self.entry_name.delete(0, GUI.END)

        self._file_name = ''

        return

    def CmdSave(self):
        self._file_name = self.entry_name.get().strip()

        if self._file_name == '':
            tkMessageBox.showwarning("Invalid Input", "Name can not be null")
            return

        # Get input and write into a file
        e_contact = ET.Element('contact')
        e_name = ET.SubElement(e_contact, 'name')
        e_name.text = self.entry_name.get().strip()
        
        e_phone = ET.SubElement(e_contact, 'phone')
        e_phone.text = self.entry_phone.get().strip()

        etree = ET.ElementTree(e_contact)
        etree.write(self._file_name)

        return   

# aplication window
app_win = GUI.Tk()

# init app
app_imp = App(app_win)

# main loop
app_win.mainloop()



