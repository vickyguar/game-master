# game-master

game-master es un juego de estrategia por turnos inspirado en T.E.G. Dos jugadores compiten por conquistar los territorios del mapa elegido, usando tropas de caballeros, magos y arqueros.

## Cómo se juega

- Elegí uno de los tres mapas: Argentina y sus países limítrofes, América Latina o Springfield.
- Los territorios y las tropas iniciales se reparten aleatoriamente entre los dos jugadores.
- En cada turno se pueden atacar territorios limítrofes y elegir las tropas que participan en la batalla.
- Las clases de guerrero tienen ventajas de combate distintas; al terminar las rondas se incorporan tropas.
- La partida termina cuando un jugador conquista todos los territorios o se alcanza el máximo de rondas.

## Estructura

```text
.
├── assets/
│   ├── ascii/            # Portada, victoria y arte de los mundos
│   ├── audio/            # Música y efectos WAV
│   ├── maps/             # Datos de territorios y fronteras que carga el juego
│   └── reference-maps/   # Imágenes de referencia conservadas
├── docs/
│   ├── diagrams/         # Diagrama de casos de uso y archivos UML
│   └── notes/            # Nota histórica sobre el flujo del juego
├── src/                  # Solución C++: juego, jugadores, mundo, países y tropas
├── GameMaster.sln
└── README.md
```

## Diagramas y recursos

- [Diagrama de casos de uso](docs/diagrams/use-case.png)
- [Documento UML en PDF](docs/diagrams/uml.pdf) y [archivo editable de Enterprise Architect](docs/diagrams/uml.eap)
- [Nota de diseño sobre el flujo del juego](docs/notes/gameplay-flow.txt)

Las imágenes de referencia y capturas históricas se conservan en el repositorio y en los enlaces de abajo; las imágenes de `assets/reference-maps/` son material de referencia y no se cargan durante la partida.

## Contribuciones

- [Victoria Guarnieri](https://github.com/vickyguar)
- [Manuela Velloso](https://github.com/manuvelloso)
- [Mailén Zino](https://github.com/MailenZino)

![Captura del juego](https://github.com/vickyguar/GAME-MASTER/assets/84190435/d5623f0b-d34f-4297-b47e-25764a83a324)
![Captura del juego](https://github.com/vickyguar/GAME-MASTER/assets/84190435/54aaebf0-f33a-4d8e-82ea-d2495eaa64ea)
