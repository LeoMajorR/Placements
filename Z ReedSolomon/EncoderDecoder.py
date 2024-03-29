import tkinter as tk
import qrcode
from qrcode.util import *
from PIL import ImageTk, Image
import reedsolo


class App(tk.Tk):

    def __init__(self):
        super().__init__()

        self.title("Reed-Solomon Encoding and Decoding App")

        # Set default font and colors
        font_family = "Helvetica"
        font_size = 12
        bg_color = "#f0f0f0"
        fg_color = "#333333"

        # Create labels and entry widgets for input
        self.message_label = tk.Label(self,
                                      text="Enter a message:",
                                      font=(font_family, font_size),
                                      bg=bg_color,
                                      fg=fg_color)
        self.message_label.pack(pady=5)

        self.message_entry = tk.Entry(self,
                                      font=(font_family, font_size),
                                      bg=bg_color,
                                      fg=fg_color,
                                      highlightbackground=fg_color,
                                      highlightcolor=fg_color,
                                      highlightthickness=1)
        self.message_entry.pack(padx=10, pady=5)

        # Create buttons to encode and decode the message
        self.encode_button = tk.Button(self,
                                       text="Encode",
                                       font=(font_family, font_size),
                                       bg=fg_color,
                                       fg=bg_color,
                                       activebackground=fg_color,
                                       activeforeground=bg_color,
                                       command=self.encode_message)
        self.encode_button.pack(pady=10)

        self.decode_button = tk.Button(self,
                                       text="Decode",
                                       font=(font_family, font_size),
                                       bg=fg_color,
                                       fg=bg_color,
                                       activebackground=fg_color,
                                       activeforeground=bg_color,
                                       command=self.decode_message)
        self.decode_button.pack(pady=10)

        # Create label to display the result
        self.result_label = tk.Label(self,
                                     font=(font_family, font_size),
                                     bg=bg_color,
                                     fg=fg_color)
        self.result_label.pack(pady=10)

    def encode_message(self):
        # Get the input message from the entry widget
        message = self.message_entry.get()

        # Encode the message using Reed-Solomon coding
        rs = reedsolo.RSCodec(10)
        data = bytearray(message.encode('utf-8'))
        encoded_message = rs.encode(data).hex()

        # Display the encoded message as a QR code
        qr = qrcode.QRCode(version=None,
                           error_correction=qrcode.constants.ERROR_CORRECT_L,
                           box_size=10,
                           border=4)
        qr.add_data(encoded_message)
        qr.make(fit=True)
        img = qr.make_image(fill_color="black", back_color="white")
        img_tk = ImageTk.PhotoImage(img)
        qr_label = tk.Label(self, image=img_tk)
        qr_label.image = img_tk
        qr_label.pack(pady=10)

        # Update the result label to show the encoded message
        self.result_label.configure(
            text=f"The encoded message is: {encoded_message}")

    def decode_message(self):
        # Get the input codeword from the entry widget
        codeword = self.message_entry.get()

        # Decode the codeword using Reed-Solomon coding
        rs = reedsolo.RSCodec(10)
        try:
            data = rs.decode(bytes.fromhex(codeword))
            decoded_message = data.decode('utf-8')
            success = True
        except reedsolo.ReedSolomonError:
            decoded_message = "Error: Unable to decode message."
            success = False

        # Update the result
        if success:
            # Display the decoded message as a QR code
            qr = qrcode.QRCode(
                version=None,
                error_correction=qrcode.constants.ERROR_CORRECT_L,
                box_size=10,
                border=4)
            qr.add_data(decoded_message)
            qr.make(fit=True)
            img = qr.make_image(fill_color="black", back_color="white")
            img_tk = ImageTk.PhotoImage(img)
            qr_label = tk.Label(self, image=img_tk)
            qr_label.image = img_tk
            qr_label.pack(pady=10)
        # Update the result label to show the decoded message

        self.result_label.configure(
            text=f"The decoded message is: {decoded_message}")


if __name__ == "__main__":
    app = App()
    app.mainloop()
