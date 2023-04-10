import sys

sys.path.append('..')

from reedSolo import RSCodec
import tkinter as tk


class Application(tk.Frame):

    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()
        self.encoded_message = None
        self.decoded_message = None

    def create_widgets(self):
        self.heading = tk.Label(self,
                                text="Reed-Solomon Encoder/Decoder",
                                font=("Helvetica", 26))
        self.heading.pack(side="top")

        self.input_label = tk.Label(self,
                                    text="Input Message",
                                    font=("Helvetica", 16))
        self.input_label.pack(side="top")

        self.input = tk.Entry(self)
        self.input.pack(side="top")

        self.encode = tk.Button(self,
                                text="Encode",
                                command=self.encode,
                                background="green")
        self.encode.pack(side="top")

        self.decode = tk.Button(self,
                                text="Decode",
                                command=self.decode,
                                background="yellow")
        self.decode.pack(side="top")

        self.clear = tk.Button(self,
                               text="Clear",
                               command=self.clear,
                               background="red")
        self.clear.pack(side="top")

        self.exit = tk.Button(self,
                              text="Exit",
                              command=self.exit,
                              background="blue")
        self.exit.pack(side="top")

        self.message_label = tk.Label(self,
                                      text="Input Message",
                                      font=("Helvetica", 16))
        self.message_label.pack(side="top")

        self.encoded_label = tk.Label(self,
                                      text="Encoded Message",
                                      font=("Helvetica", 16))
        self.encoded_label.pack(side="top")

        self.decoded_label = tk.Label(self,
                                      text="Decoded Message",
                                      font=("Helvetica", 16))
        self.decoded_label.pack(side="top")

    def encode(self):
        input = self.input.get()
        rs = RSCodec(10)
        self.encoded_message = rs.encode(input.encode())
        self.message_label.config(text="Input Message: " + input)
        self.encoded_label.config(text="Encoded Message: " +
                                  str(self.encoded_message))

    def decode(self):
        rs = RSCodec(10)
        self.decoded_message = rs.decode(self.encoded_message)
        self.decoded_label.config(text="Decoded Message: " +
                                  str(self.decoded_message[0].decode()))

    def clear(self):
        self.input.delete(0, tk.END)
        self.message_label.config(text="Input Message")
        self.encoded_label.config(text="Encoded Message")
        self.decoded_label.config(text="Decoded Message")

    def exit(self):
        self.master.destroy()


root = tk.Tk()
app = Application(master=root)
app.mainloop()
