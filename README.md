# so_long

A small 2D game written in **C** with **MiniLibX**, developed as part of the 42 curriculum.

The mandatory project focuses on map parsing, validation, path checking, sprite rendering and keyboard-driven movement. This version uses a **Bleach-inspired visual theme** for the XPM sprites.

## Highlights

- 2D tile-map rendering with MiniLibX
- XPM sprite loading
- `.ber` map parsing and validation
- Rectangular-map and closed-border checks
- Player, collectible and exit validation
- Reachability verification with a flood-fill/pathfinding pass
- Grid-based movement and collision handling
- Move counting
- Explicit cleanup of allocated resources and graphics objects
- Extended bonus gameplay with animated collectibles, enemies and a second controllable character

## Map format

The mandatory map uses a compact tile representation:

```text
1 = wall
0 = floor
P = player
C = collectible
E = exit
```

A valid map must be rectangular, surrounded by walls and contain exactly one player and one exit, with at least one collectible.

Example:

```text
1111111
1P000C1
1001001
1C000E1
1111111
```

## Validation before rendering

The game does not simply accept any syntactically valid grid.

Before MiniLibX starts rendering, the parser verifies the shape, borders and contents of the map. It then clones the map and runs a recursive reachability check from the player's position.

The first traversal checks that every collectible can be reached. A second traversal verifies that the exit is accessible as well.

This prevents maps that look valid on disk but cannot actually be completed.

## Rendering and movement

Each map tile is associated with an XPM sprite and drawn into the MiniLibX window.

Player input modifies the player's position only when the target tile is traversable. Collectibles are removed when picked up, and the exit can only complete the game once the required collectibles have been collected.

The render loop continuously redraws the current map state.

## Bonus version

The bonus version goes substantially beyond the mandatory requirements.

It adds:

- directional player sprites;
- animated collectible sprites;
- enemies;
- a player transformation after collecting all collectibles;
- an antagonist character;
- optional two-player controls;
- an on-screen scoreboard showing moves, remaining collectibles and enemies.

The main player uses the usual movement keys, while maps containing a second player allow the antagonist to be controlled with the arrow keys.

Enemy interactions also change after the player's transformation: enemies that were initially dangerous can then be defeated, while the antagonist remains a threat.

## Build

The current Makefile targets **macOS** and MiniLibX.

Mandatory:

```bash
make
```

Run with one of the provided maps:

```bash
./so_long maps/valid/valid_map1.ber
```

Bonus:

```bash
make bonus
./so_long_bonus maps/valid/mapswithantag_bonus.ber
```

## Controls

| Key | Action |
| --- | --- |
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Esc` | Quit |
| Arrow keys | Control the antagonist in supported bonus maps |

## Project structure

```text
so_long/
├── mandatory/      # Core project
├── bonus/          # Extended gameplay
├── maps/           # Valid and intentionally invalid test maps
├── sprites/        # XPM assets
├── includes/       # Project headers
└── libft/          # Utility library
```

The repository also contains invalid maps used to exercise parser and reachability error cases.

## What this project demonstrates

so_long links several concerns that are easy to treat separately when learning C: parsing external data, validating invariants, exploring a graph-like map, maintaining game state, reacting to input and drawing the result through a low-level graphics library.

The path validation is particularly important: a map is not considered valid merely because its characters are correct — it must also describe a game that can actually be completed.

---

Part of my developer portfolio: **[github.com/Overflow-ADW](https://github.com/Overflow-ADW)**  
Professional work: **[Avenue du Web](https://avenueduweb.be)**
