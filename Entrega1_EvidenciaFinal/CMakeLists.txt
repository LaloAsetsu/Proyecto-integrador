cmake_minimum_required(VERSION 3.29)
project(Entrega1_EvidenciaFinal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Entrega1_EvidenciaFinal
    ArbolBinario.h
    monsters.csv
    Dungeon.cpp
    Dungeon.h
    LinkedList.h
    main.cpp
    Monster.cpp
    Monster.h
    MonsterCatalog.cpp
    MonsterCatalog.h
    Nodo.h
    NodoArbol.h
    Player.h
    Room.cpp
    Room.h)
