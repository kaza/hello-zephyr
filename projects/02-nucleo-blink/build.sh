#!/bin/bash
source ~/zephyr-venv/bin/activate && cd ~/zephyrproject/zephyr && west build -b nucleo_f401re /Users/almir/Documents/GitHub/hello-zephyr/projects/02-nucleo-blink && west flash