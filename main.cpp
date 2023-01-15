#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "func.h"
#include "bat.h"
#include "ball.h"
using namespace sf;


int main()
{
    //������� 
    Bat bat;
    bat_init(bat);
    //���
    Ball ball;
    ball_init(ball);

    //����
    int player_score = 0;
    Font font;
    font.loadFromFile("DS-DIGIB.ttf");
    Text player_score_text;
    init_text(player_score_text, player_score, font, char_size, text_start_pos);

    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(window_size, window_size), "SFML Works!");

    window.setFramerateLimit(fps);

    // ������� ���� ����������. �����������, ���� ������� ����
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed) {
                // ����� ��������� ���
                window.close();
            }


        }
        Vector2f mid_left{ ball.shape.getPosition().x, ball.shape.getPosition().y + ball_r };
        Vector2f mid_right{ ball.shape.getPosition().x + 2 * ball_r, ball.shape.getPosition().y + ball_r };
        Vector2f mid_bottom{ ball.shape.getPosition().x + ball_r, ball.shape.getPosition().y + 2 * ball_r };
        //�� �������
        if (point_in_rect(bat.shape, mid_bottom)) {
            ball.speedy *= -1; 
        }
        //�� �����
        if (point_in_rect(bat.shape, mid_left)) {
            ball.speedx *= -1;
        }
        //�� ������
        if (point_in_rect(bat.shape, mid_right)) {
            ball.speedx *= -1;
        }

        bat_update(bat);
        ball_update(ball);

        window.clear();
        bat_draw(bat, window);
        ball_draw(ball, window);
        window.draw(player_score_text);
        window.display();
    }
    return 0;
}