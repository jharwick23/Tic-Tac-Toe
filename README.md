- Small little game project attempting to learn how to create a cpu for player to play against and learn opengl.

1. Create AI that is beatable yet smart

**Prioritize Winning Moves:** The AI should check if there is a move that allows it to win on the current turn. If such a move exists, the AI should make that move.

**Block User Wins:** If the user is one move away from winning, the AI should prioritize blocking that winning move.

**Create Forks:** A fork is a situation where the AI has two ways to win on the next move. The AI can try to create such situations to increase its chances of winning.

**Block User Forks:** If the user is close to creating a fork (two possible winning moves), the AI should block one of those moves.

**Center and Corners:** The center and corners are generally strong positions. The AI can prioritize occupying these positions early in the game.

**Adapt to User's Strategy:** The AI can analyze the user's moves and adapt its strategy accordingly. For example, if the user frequently goes for a certain pattern, the AI can adjust its moves to counter that pattern.
