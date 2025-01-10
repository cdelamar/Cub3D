#!/bin/zsh

for map in maps/*; do
  echo "Launching $map..."
  ./cub3d "$map"
done
