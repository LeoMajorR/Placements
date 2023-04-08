import tkinter as tk
from tkinter import font


class App(tk.Tk):

    def __init__(self):
        super().__init__()

        self.title("Addition App")

        # Set default font and colors
        font_family = font.Font(family="Helvetica", size=12)
        bg_color = "#f0f0f0"
        fg_color = "#333333"

        # Create labels and entry widgets for input
        self.num1_label = tk.Label(self,
                                   text="Enter a number:",
                                   font=font_family,
                                   bg=bg_color,
                                   fg=fg_color)
        self.num1_label.pack(pady=5)

        self.num1_entry = tk.Entry(self,
                                   font=font_family,
                                   bg=bg_color,
                                   fg=fg_color,
                                   highlightbackground=fg_color,
                                   highlightcolor=fg_color,
                                   highlightthickness=1)
        self.num1_entry.pack(padx=10, pady=5)

        self.num2_label = tk.Label(self,
                                   text="Enter another number:",
                                   font=font_family,
                                   bg=bg_color,
                                   fg=fg_color)
        self.num2_label.pack(pady=5)

        self.num2_entry = tk.Entry(self,
                                   font=font_family,
                                   bg=bg_color,
                                   fg=fg_color,
                                   highlightbackground=fg_color,
                                   highlightcolor=fg_color,
                                   highlightthickness=1)
        self.num2_entry.pack(padx=10, pady=5)

        # Create button to calculate the sum
        self.calculate_button = tk.Button(self,
                                          text="Calculate Sum",
                                          font=font_family,
                                          bg=fg_color,
                                          fg=bg_color,
                                          activebackground=fg_color,
                                          activeforeground=bg_color,
                                          command=self.calculate_sum)
        self.calculate_button.pack(pady=10)

        # Create label to display the result
        self.result_label = tk.Label(self,
                                     font=font_family,
                                     bg=bg_color,
                                     fg=fg_color)
        self.result_label.pack(pady=10)

    def calculate_sum(self):
        # Get the input values from the entry widgets and validate them
        try:
            num1 = float(self.num1_entry.get())
            num2 = float(self.num2_entry.get())
        except ValueError:
            self.result_label.configure(
                text="Invalid input! Please enter valid numbers.")
            return

        # Calculate the sum and display the result
        result = num1 + num2
        self.result_label.configure(
            text=f"The sum of {num1:.2f} and {num2:.2f} is {result:.2f}")


if __name__ == "__main__":
    app = App()
    app.configure(bg="#ffffff")
    app.mainloop()
