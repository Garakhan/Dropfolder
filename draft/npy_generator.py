"""
Generates random 2D numpy array and writes it to .npy file.
"""

import os, sys
from typing import Tuple
import ast
import argparse
import numpy as np


def tuple_type(string: str):
    """
    Parser for tuple object in argparser.

    Params:
    string: passed argument through command line interface

    Returns:
    Parsed string to a tuple.

    Raises:
    ValueError: if parsed tupled is not of shape 2 dims. 
    argaprase.ArguemtnTypeError if passed cli argument cannot be parsed into tuple.
    """
    try:
        tpl = tuple(map(int, string.split(',')))
        if not isinstance(tpl, tuple):
            raise ValueError(f"Received {tpl} is not instance of tuple")
        elif len(tpl)!=2:
            raise ValueError(f"Received {tpl} length is not 2.")
        return tpl
    except(ValueError, SyntaxError):
        raise argparse.ArgumentTypeError(f"Invalid tuple format: {string}")

 
def generate_npy(shape: Tuple[int]=(10, 10),
                 file_name: str="npy_file.npy",
                 test: bool=False):
    """
    Generates random 2D numpy array and writes to .npy file.

    Params:
    shape: shape of generated array.
    file_name: file name for .npy.
    test: bool object whether to test after writing to .npy file. Test is done by   loading the written .npy file and check its shape and values.
    
    Returns:
    None. Writes to file_name
    """
    vect = np.random.randn(*shape)
    with open(file_name, "wb") as f:
        np.save(f, vect)
        print(f"{file_name} successfully written.")
        print(f"""
              Params:
              -------
              shape: {shape}
              file_name: {file_name}
              """)
    if test:
        try:
            load_vect = np.load(file_name)
        except:
            raise Exception(f"Cannot load {file_name}")
        if ((load_vect==vect).all()) and load_vect.shape==shape:
            print(f"Everything is fine.")
        else:
            print(f"{file_name} loaded, but it is not the same numpy matrix written to {file_name}.")

if __name__=="__main__":
    parser = argparse.ArgumentParser(
        prog=".npy generator",
        description="Generating .npy file with random normal matrix."
    )
    parser.add_argument("--s", "--shape", default=(10, 10), type=tuple_type)
    parser.add_argument("--f", "--file-name", default="npy_file.npy")
    parser.add_argument("--t", "--test", action="store_true")
    args = parser.parse_args()
    file_name = args.f
    shape = args.s
    test = args.t
    try:
        generate_npy(shape, file_name, test)
    except:
        raise Exception(f"Could not write {file_name}")