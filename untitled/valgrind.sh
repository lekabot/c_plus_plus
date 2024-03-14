#!/bin/zsh

if [ -e "test" ]; then
    docker build -t valgrind_container . && docker run -it valgrind_container
else
    echo "Ошибка: файл 'test' не найдена в текущей директории."
fi
