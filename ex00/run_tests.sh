#!/bin/bash

INPUT_FILE="inputs.txt"

if [[ ! -f "$INPUT_FILE" ]]; then
  echo "Arquivo '$INPUT_FILE' não encontrado."
  exit 1
fi

echo "Iniciando testes com '$INPUT_FILE'..."

while IFS= read -r line || [[ -n "$line" ]]; do
  echo -e "\033[1;32m>>> ./convert \"$line\"\033[0m"
  ./convert "$line"
  echo
  read -p "Pressione ENTER para continuar..."
done < "$INPUT_FILE"
