#!/bin/bash

echo " "
read -p "quel année es tu né(e) ? " a
date=$(date +%Y)
let age=date-a
echo " "
echo " "
echo "tu as $age ans"
