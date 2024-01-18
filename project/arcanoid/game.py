import pygame
from pygame.locals import *
import time
from tkinter import *
from tkinter.ttk import Combobox

def game(ballspeed, platspeed, WIDTH, HEIGHT):
    # Инициализация Pygame
    pygame.init()

    #музыка
    pygame.mixer.music.load("SYNTHWAVE MUSIC   - - - C O S M I C - - -.mp3")
    pygame.mixer.music.play(-1)
    pygame.mixer.music.set_volume(0.55)
    #platform
    #pls = pygame.mixer.Sound("Discord Leave - Sound Effect (HD).ogg")
    #blocks
    bls = pygame.mixer.Sound("Minecraft Glass Break - Sound Effect (HD).ogg")
    #gameover
    gos = pygame.mixer.Sound("Game Over.ogg")
    #gamewin
    gwis = pygame.mixer.Sound("Congratulations Sound Effect.ogg")
    #walls
    #gws = pygame.mixer.Sound("Discord Leave - Sound Effect (HD).ogg")

    # Определение размеров экрана
    SCREEN_WIDTH = WIDTH
    SCREEN_HEIGHT = HEIGHT

    # Определение цветов
    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    BLUE = (0, 0, 255)
    RED = (255, 0, 0)
    GREEN = (80,150,0)
    ANOTHER = (255,50,0)

    # Создание экрана
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Арканоид")

    boyut = (SCREEN_WIDTH, SCREEN_HEIGHT)
    background = pygame.image.load('zavod.JPG').convert()
    background = pygame.transform.scale(background, (boyut))

    # Определение размеров и положения платформы
    PLATFORM_WIDTH = 100
    PLATFORM_HEIGHT = 10
    platform_x = (SCREEN_WIDTH - PLATFORM_WIDTH) // 2
    platform_y = SCREEN_HEIGHT - 50

    # Определение скорости и направления мяча
    ball_radius = 10
    ball_x = SCREEN_WIDTH // 2
    ball_y = SCREEN_HEIGHT // 2
    ball_dx = ballspeed
    ball_dy = ballspeed

    # Определение размеров и положения кирпичей
    BRICK_WIDTH = 60
    BRICK_HEIGHT = 20
    brick_rows = 5
    brick_cols = SCREEN_WIDTH // BRICK_WIDTH
    brick_color = [BLUE, RED, GREEN]
    bricks = []
    brickscol = []
    for row in range(brick_rows):
        for col in range(brick_cols):
            brick_x = col * BRICK_WIDTH
            brick_y = 75 + row * BRICK_HEIGHT
            bricks.append(pygame.Rect(brick_x, brick_y, BRICK_WIDTH, BRICK_HEIGHT))
            brickscol.append(pygame.Rect(brick_x, brick_y, BRICK_WIDTH, BRICK_HEIGHT))

    clock = pygame.time.Clock()

    running = True

    while running:
        clock.tick(75)  # Ограничение FPS до 60

        # Обработка событий
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False

        # Движение платформы влево/вправо при нажатии клавиш
        keys = pygame.key.get_pressed()
        if keys[K_LEFT]:
            if (platform_x != 0):
                    platform_x -= platspeed
        if keys[K_RIGHT]:
            if (platform_x !=SCREEN_WIDTH - PLATFORM_WIDTH):
                platform_x += platspeed

        # Обновление позиции мяча
        ball_x += ball_dx
        ball_y += ball_dy

        # Отскок мяча от границ экрана
        if ball_x < ball_radius or ball_x > SCREEN_WIDTH - ball_radius:
            ball_dx *= -1
            #gws.play()
        if ball_y < ball_radius:
            ball_dy *= -1
            #gws.play()

        # Отскок мяча от платформы
        if ball_y > platform_y - ball_radius and platform_x - ball_radius < ball_x < platform_x + PLATFORM_WIDTH + ball_radius:
            #sound
            #pls.play()
            ball_dy *= -1

        # Проверка столкновений с кирпичами
        for brick in bricks:
            if brick.colliderect(pygame.Rect(ball_x - ball_radius, ball_y - ball_radius, ball_radius * 2, ball_radius * 2)):
                ball_dy *= -1
                #sound
                bls.play()
                bricks.remove(brick)
                break

        # Очистка экрана
        screen.blit(background, (0, 0))
        # Рисование платформы
        pygame.draw.rect(screen, RED, (platform_x, platform_y, PLATFORM_WIDTH, PLATFORM_HEIGHT))

        # Рисование мяча
        pygame.draw.circle(screen, ANOTHER, (ball_x, ball_y), ball_radius)

        # Рисование кирпичей
        for brick in bricks:
            brick_color_index = brickscol.index(brick) % len(brick_color)  # Исправлено здесь
            pygame.draw.rect(screen, brick_color[brick_color_index], brick)

        # Обновление экрана
        pygame.display.flip()

        if SCREEN_HEIGHT < ball_y:
            print('GAME OVER!')
            #sound
            gos.play()
            time.sleep(1.3)
            break
        if len(bricks) == 0:
            print('WIN')
            #sound
            gwis.play()
            time.sleep(7.2)
            break

    # Завершение Pygame
    pygame.quit()


def easy():
    WIDTH, HEIGHT = resolution(combo.get())
    game(4, 5, WIDTH, HEIGHT)

def standart():
    WIDTH, HEIGHT = resolution(combo.get())
    game(4,6, WIDTH, HEIGHT)

def fast():
    WIDTH, HEIGHT = resolution(combo.get())
    game(5, 6, WIDTH, HEIGHT)

def veryfast():
    WIDTH, HEIGHT = resolution(combo.get())
    game(7, 9, WIDTH, HEIGHT)

def resolution(res):
    if res == '600*500':
        SCREEN_WIDTH = 600
        SCREEN_HEIGHT = 500
        return SCREEN_WIDTH, SCREEN_HEIGHT
    if res == '780*600':
        SCREEN_WIDTH = 780
        SCREEN_HEIGHT = 600
        return SCREEN_WIDTH, SCREEN_HEIGHT
    if res == '1200*600':
        SCREEN_WIDTH = 1200
        SCREEN_HEIGHT = 600
        return SCREEN_WIDTH, SCREEN_HEIGHT

#создание экрана настроек
window = Tk()
window.title("Arcanoid settings")
window.geometry('350x300')
lbl = Label(window, text="Выберете сложность", font=("Arial Bold", 25))
lbl.grid(column=0, row=0)
#создание кнопок
btn = Button(window, text="легко", font=("Arial Bold", 15), bg='red',fg='white', command=easy)
btn.grid(column=0, row=1)
btn2 = Button(window, text="стандарт", font=("Arial Bold", 15), bg='red',fg='white', command=standart)
btn2.grid(column=0, row=2)
btn3 = Button(window, text="быстро", font=("Arial Bold", 15), bg='red',fg='white', command=fast)
btn3.grid(column=0, row=3)
btn4 = Button(window, text="очень быстро", font=("Arial Bold", 15), bg='red',fg='white', command=veryfast)
btn4.grid(column=0, row=4)

#создание списков
lbl2 = Label(window, text="Разрешение", font=("Arial Bold", 15))
lbl2.grid(column=0, row=5)
combo = Combobox(window)
combo['values'] = ("600*500", "780*600", "1200*600")
combo.current(0)
combo.grid(column=0, row=6)



window.mainloop()


