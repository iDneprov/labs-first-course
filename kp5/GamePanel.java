import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class GamePanel extends JPanel implements ActionListener {
    static final int SCREEN_WIDTH = 500;
    static final int SCREEN_HEIGHT = 500;
    static final int UNIT_SIZE = 20;
    static final int GAME_UNIT_CAPACITY = (SCREEN_WIDTH * SCREEN_HEIGHT) / (UNIT_SIZE * UNIT_SIZE);
    static final int DELAY = 100;
    int[] x = new int[GAME_UNIT_CAPACITY];
    int[] y = new int[GAME_UNIT_CAPACITY];
    int snakeSize;
    int score;
    char direction;
    char currentDirection;
    int goalX;
    int goalY;
    boolean active = false;
    Timer timer;
    Random random;

    // draw constants
    // adjusted coordinates
    static final double goalAdj = 1.0;
    static final double headAdj = 1.0;
    static final double partAdj = 1.0;
    // colors;
    static final Color goalColor = Color.YELLOW;
    static final Color headColor = Color.WHITE;
    static final Color partColor = Color.GRAY;
    static final Color backgroundColor = Color.BLACK;
    static final Color gameOverColor = Color.WHITE;
    static final Color scoreColor = Color.WHITE;
    static final Color restartColor = Color.WHITE;
    // draw
    static final boolean drawGrid = false;
    static final boolean drawScore = true;
    //
    static final String gameOverMessage = "GAME OVER";
    static final String restartMessage = "Press <SPACE> to try again";
    static final String font = "Consolas";

    GamePanel() {
        random = new Random();
        this.setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
        this.setBackground(backgroundColor);
        this.setFocusable(true);
        this.addKeyListener(new GameKeyAdapter());
        startGame();
    }

    public void startGame() {
        x = new int[GAME_UNIT_CAPACITY];
        y = new int[GAME_UNIT_CAPACITY];
        snakeSize = 5;
        score = 0;
        direction = 'R';
        currentDirection = 'R';
        newGoal();
        active = true;
        timer = new Timer(DELAY, this);
        timer.start();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }

    public void draw(Graphics g) {
        if (active) {
            if (drawGrid) {
                for (int i = 0; i < SCREEN_HEIGHT; i += UNIT_SIZE) {
                    g.drawLine(0, i, SCREEN_WIDTH, i);
                }
                for (int i = 0; i < SCREEN_WIDTH; i += UNIT_SIZE) {
                    g.drawLine(i, 0, i, SCREEN_HEIGHT);
                }
            }
            g.setColor(goalColor);
            g.fillRect(adjustCoordinate(goalX, goalAdj),
                    adjustCoordinate(goalY, goalAdj),
                    adjustSize(goalAdj),
                    adjustSize(goalAdj));

            for (int i = 0; i < snakeSize; i++) {
                if (i == 0) {
                    g.setColor(headColor);
                    g.fillRect(adjustCoordinate(x[0], headAdj),
                            adjustCoordinate(y[0], headAdj),
                            adjustSize(headAdj),
                            adjustSize(headAdj));
                } else {
                    g.setColor(partColor);
                    g.fillRect(adjustCoordinate(x[i], partAdj),
                            adjustCoordinate(y[i], partAdj),
                            adjustSize(partAdj),
                            adjustSize(partAdj));
                }
            }
            if (drawScore) {
                g.setColor(scoreColor);
                g.setFont(new Font(font, Font.PLAIN, 32));
                FontMetrics metrics = getFontMetrics(g.getFont());
                g.drawString("Score: " + score,
                        (SCREEN_WIDTH - metrics.stringWidth("Score: " + score)) / 2,
                        g.getFont().getSize());
            }
        } else {
            gameOver(g);
        }
    }

    public void newGoal() {
        goalX = random.nextInt(SCREEN_WIDTH / UNIT_SIZE);
        goalY = random.nextInt(SCREEN_HEIGHT / UNIT_SIZE);
        for (int i = 0; i < snakeSize; i++) {
            if (goalX == x[i] && goalY == y[i]) {
                newGoal();
                break;
            }
        }
    }

    public void move() {
        currentDirection = direction;
        for (int i = snakeSize; i > 0; i--) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        int dx = 0;
        int dy = 0;
        switch (direction) {
            case 'R':
                dx = 1;
                break;
            case 'L':
                dx = -1;
                break;
            case 'U':
                dy = -1;
                break;
            case 'D':
                dy = 1;
                break;
        }
        x[0] = x[0] + dx;
        y[0] = y[0] + dy;
    }

    public void checkGoal() {
        if (x[0] == goalX && y[0] == goalY) {
            snakeSize++;
            score++;
            newGoal();
        }
    }

    public void checkCollisions() {
        for (int i = snakeSize; i > 0; i--) {
            if (x[0] == x[i] && y[0] == y[i]) {
                active = false;
                break;
            }
        }
        if (x[0] < 0 || x[0] >= SCREEN_WIDTH / UNIT_SIZE || y[0] < 0 || y[0] >= SCREEN_HEIGHT / UNIT_SIZE) {
            active = false;
        }
        if (!active) {
            timer.stop();
        }
    }

    public void gameOver(Graphics g) {
        int currentY = 0;
        {
            g.setColor(gameOverColor);
            g.setFont(new Font(font, Font.BOLD, 64));
            FontMetrics metrics = getFontMetrics(g.getFont());
            currentY += SCREEN_HEIGHT / 2;
            g.drawString(gameOverMessage,
                    (SCREEN_WIDTH - metrics.stringWidth(gameOverMessage)) / 2,
                    currentY);
        }
        {
            g.setColor(scoreColor);
            g.setFont(new Font(font, Font.PLAIN, 32));
            FontMetrics metrics = getFontMetrics(g.getFont());
            currentY += g.getFont().getSize() * 2;
            g.drawString("Score: " + score,
                    (SCREEN_WIDTH - metrics.stringWidth("Score: " + score)) / 2,
                    currentY);
        }
        {
            g.setColor(restartColor);
            g.setFont(new Font(font, Font.PLAIN, 16));
            FontMetrics metrics = getFontMetrics(g.getFont());
            currentY += g.getFont().getSize() * 2;
            g.drawString(restartMessage,
                    (SCREEN_WIDTH - metrics.stringWidth(restartMessage)) / 2,
                    currentY);
        }
    }

    public int adjustCoordinate(int coordinate, double value) {
        return coordinate * UNIT_SIZE + (int)((1.0 - value) / 2.0 * UNIT_SIZE);
    }

    public int adjustSize(double value) {
        if (value != 1.0) {
            return (int)(UNIT_SIZE * value) + 1;
        } else {
            return (int)(UNIT_SIZE * value);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (active) {
            move();
            checkGoal();
            checkCollisions();
        }
        repaint();

    }

    public class GameKeyAdapter extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            switch(e.getKeyCode()) {
                case KeyEvent.VK_LEFT:
                    if (currentDirection != 'R') {
                        direction = 'L';
                    }
                    break;
                case KeyEvent.VK_RIGHT:
                    if (currentDirection != 'L') {
                        direction = 'R';
                    }
                    break;
                case KeyEvent.VK_UP:
                    if (currentDirection != 'D') {
                        direction = 'U';
                    }
                    break;
                case KeyEvent.VK_DOWN:
                    if (currentDirection != 'U') {
                        direction = 'D';
                    }
                    break;
                case KeyEvent.VK_SPACE:
                    if (!active) {
                        startGame();
                    }
                    break;
            }
        }
    }
}
