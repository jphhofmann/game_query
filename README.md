# game_query
Simple C tool to query gameservers.

## Usage
`gcc game.c -o game`

Afterwards:

`./game IP PORT`

Sample Response:

`jhofmann@naya:~/git/game_query$ ./game 160.20.145.233 27015
����ILinuxGSM
`

Currently works only with Source Engine (Port 27-28000) and FiveM (30-32000).
