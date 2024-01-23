import ctypes
from ctypes import CDLL, c_double, c_int
shared_library = ctypes.CDLL('./monte_carlo.dylib')

simulateBlackJack = shared_library.simulateBlackJack

simulateBlackJack.argtypes = [c_int, c_double, c_double,
                          c_double, c_double, c_double, c_double,
                          c_double, c_double, c_double, c_double,
                          c_double, c_double]

simulateBlackJack.restype = c_double

get_std_dev = shared_library.get_std_dev
get_std_dev.restype = c_double

import tkinter as tk
from tkinter import ttk
import asyncio

class App(tk.Tk):
    num_decks = 1
    betting_unit = 0.001

    def __init__(self):
        super().__init__()

        self.title('BlackJack Strategy')

        self.resizable(0,0)

        # so i don't have to keep track of what row to put things
        self.curr_row = 0

        self.create_intro()
        self.bankroll_widget()
        self.betting_unit_widget()
        self.decks_option()
        self.create_value_widgets()
        self.create_num_shoes_widget()
        self.submit_and_results_widget()

    def create_intro(self):
        # change to a more suitable title
        title_label = ttk.Label(self, text="Title Here")
        title_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)
        self.curr_row += 1

    def bankroll_widget(self):
        card_label = ttk.Label(self, text="Bankroll")
        card_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)
        self.curr_row += 1

        card_entry = ttk.Entry(self)
        card_entry.grid(column=1, row=self.curr_row, sticky=tk.E, padx=5, pady=5)
        self.curr_row += 1

        self.br_widget = card_entry

    def betting_unit_widget(self):
        card_label = ttk.Label(self, text="Betting unit (baseline proportion of bankroll to bet)")
        card_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)

        card_entry = ttk.Entry(self)
        card_entry.grid(column=1, row=self.curr_row, sticky=tk.E, padx=5, pady=5)

        self.curr_row += 1
        self.bu_widget = card_entry

    def decks_option(self):
        # number of decks, up to ten
        decks_label = ttk.Label(self, text="Number of decks")
        decks_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)

        decks_button = tk.Menubutton(self, text="Select an Option", relief="raised", indicatoron=True, direction="above", anchor="w")
        decks_button.grid(column=1, row=self.curr_row, sticky=tk.E, padx=5, pady=5)
        self.curr_row += 1

        deck_options = tk.Menu(decks_button, tearoff=False)
        for i in range(1, 11):
            deck_options.add_command(label=f"{i}", command=lambda num=i: on_deck_selection(num))
        
        def on_deck_selection(num):
            if num == 1:
                decks_button.config(text="1 Deck")
            else:
                decks_button.config(text=f"{num} Decks")
            self.num_decks = num
        
        decks_button['menu'] = deck_options


    def create_value_widgets(self):
        self.value_entry_widgets = [] # to keep track of all the

        # count value of each card
        cards = ['Ace', '2', '3', '4', '5', '6', '7', '8', '9', '10/Face']

        for card in cards:
            card_label = ttk.Label(self, text=card)
            card_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)

            card_entry = ttk.Entry(self)
            card_entry.grid(column=1, row=self.curr_row, sticky=tk.E, padx=5, pady=5)

            self.value_entry_widgets.append(card_entry)
            self.curr_row += 1
    
    def create_num_shoes_widget(self):
        card_label = ttk.Label(self, text="Number of simulated shoes")
        card_label.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)

        card_entry = ttk.Entry(self)
        card_entry.grid(column=1, row=self.curr_row, sticky=tk.E, padx=5, pady=5)

        self.curr_row += 1
        self.num_shoes_widget = card_entry
    
    def submit_and_results_widget(self):
        # button to submit form
        submit_button = ttk.Button(self, text="Calculate", command=lambda: self.submit())
        submit_button.grid(column=1,row=self.curr_row, sticky=tk.E, padx=5, pady=5)
        self.curr_row += 1
        # area to show results
        results = ttk.Label(self)
        results.config(text='')
        results.grid(column=0, row=self.curr_row, sticky=tk.W, padx=5, pady=5)
        self.results = results
        self.curr_row += 1

    
    def submit(self):
        self.results.config(text="Calculating")
        self.after(0, self.calculate)
        
    def calculate(self):
        # self.results.config(text="Calculating")
        # form the requests in a readable format

        num_decks = self.num_decks
        bankroll = float(self.br_widget.get())

        num_shoes, betting_unit, bankroll = 0,0,0
        try:
            num_shoes = int(self.num_shoes_widget.get())
            betting_unit = float(self.bu_widget.get())
            bankroll = float(self.br_widget.get())
        except:
            # change the text in the results widget
            self.results.config(text="Error occurred")


        values = [0.0]
        for entry_widget in self.value_entry_widgets:
            value = entry_widget.get()
            values.append(float(value))

        # send it to the C++ file
        print('num decks:', num_decks, 'bankroll:', bankroll, 'betting unit:', betting_unit)
        print('values:', values)
        print(num_shoes)

        average_gain, std_dev_results = 0,0
        average_gain = simulateBlackJack(num_decks, betting_unit, bankroll,
                                          values[1], values[2], values[3], values[4], values[5], values[6],
                                          values[7], values[8], values[9], values[10])
        std_dev_results = get_std_dev()

        # return properly

        self.results.config(text=("Average Gain/Loss:", str(average_gain), "Standard Deviation:", std_dev_results))

            
    # def error_message(self):


if __name__ == "__main__":
    app = App()
    app.mainloop()
