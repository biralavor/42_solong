# So_long -> Let's save the Astronauts!

| ![so_longm](https://github.com/biralavor/42_solong/assets/80487147/f760aaf0-3431-4fe8-81a2-09aa87535608) | A 2D game built in Linux without any game engine, <br> just math a graphic library to handle my PNGs files <br> and a lot of boolean functions | ![105sucess](https://github.com/biralavor/42_solong/assets/80487147/7d94b14f-1c64-466d-8804-c636d59d6518) <br> My grade at 42 School: 105% |
| :-: | :-: | :-: |

![Screenshot from 2024-04-14 10-04-21](https://github.com/biralavor/42_solong/assets/80487147/9ab01979-2f1d-453f-af1b-fe9897ac9033)

> [!Note]
> This is a common core project from https://42.fr


# Main goal:
  - Build a game in C language
  - Use a graphic library (minilibX or MLX42codam)

# Features
- Build your own map, using:
  - '1' for walls (my Asteroids)
  - '0' for vacuum space
  - 'P' for starting Player position
  - 'E' for Exit
  - 'C' for Coins (my Astronauts)
  - && Map rules!
- Move the player with keyboard arrows and WASD keys
- Collect coins
- Exit the game gracefully!
- A LOT of feedback messages on the Linux terminal
- Prebuilt game maps for playing and system validation tests:
  - map file extension - needs to be '.ber'
  - bad format - is your map rectangular?
  - illegal char in map
  - locked item in map
  - tiny map
  - big map
  - wall - do you have a breach on the wall?
  - items_to_check - I've build this map to help users understand about map validation. Try it!

# Bonus Features
- Text on screen
- New terminal messages
- Enemy patrol (you have to figure it out who is your enemy!)
- New Game rules 🤔

![image](https://github.com/user-attachments/assets/914d452d-2a91-4e0b-9578-4379d62793d6)


# The code
## 100% boolean functions for map validation

  ![Screenshot from 2024-04-15 10-06-51](https://github.com/biralavor/42_solong/assets/80487147/c560c576-bcda-46da-a710-cb824b560a40)


# Evaluation feedbacks:
## The approach to Boolean functions was very cool!
> _"The bonus gameplay was incredible, perhaps the first so_long that made you want to keep replaying it. Bira explained the code very well and you could see that he had more audacious plans for the project, it's a shame he didn't have time to implement everything. Congratulations on the project, Bira!!!"_ (Cadet actual project: so_long)

## It was very beautiful done and with lots of contextual details.
> _"Congratulations on the project, Bira! Good luck with your next training projects. Cheers!"_ (Cadet actual project: transcendence)

## Awesome project!
> _"Bira did an excellent job implementing his game. In addition to adding non-mandatory features to the project, he took great care to think about gameplay and user experience, printing personalized messages on the terminal for each scenario and movement within the game. Not to mention that the code was very well structured and organized: most of the functions were standardized with Boolean return, which I thought was brilliant. Clean and easy to understand code. Congratulations! You have masterfully mastered the so_long concepts and functionalities."_ (Cadet actual project: minishell)


---

> All 42 Badges -- the astronomer Human Coder -- were done by Larissa Cristina [@mewmewdevart](https://github.com/mewmewdevart/42Badges)
