#!/bin/bash

echo " "
read -p "quel ann�e es tu n�(e) ? " a
date=$(date +%Y)
let age=date-a
echo " "
echo " "
echo "tu as $age ans"
