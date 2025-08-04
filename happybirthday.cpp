#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

struct LyricLine
{
    float time; // thời gian (giây)
    std::string text;
};

// Gán thời điểm từng câu cho dễ đồng bộ, ví dụ 0s, 4s, 8s,...
const std::vector<LyricLine> lyrics = {
    {0.0f, "Girl, anh đã say mùi hương ấy"},
    {4.0f, "Thôi rồi, tim của anh đã bị em cướp lấy"},
    {8.0f, "Anh thích vị ngọt em chọn cho đêm nay đó!"},
    {12.0f, "Sà vào lòng anh để ta cùng thơm nhớ"},
    {16.0f, "Trông là biết em FA"},
    {18.0f, "Mà F to the A N C to the Y"},
    {21.0f, "Nghe nói em cần một bờ vai"},
    {24.0f, "Nhưng tính anh rộng lượng cho luôn một đêm never phai"},
    {28.0f, "Em cần một người đàn ông làm bạn trai"},
    {32.0f, "Không phải là một thằng con trai tập làm đàn ông"},
    {36.0f, "Đã từng có cho mình quá nhiều lựa chọn sai"},
    {40.0f, "Nên là nay đã miễn nhiễm với những lời mật ngọt"},
    {44.0f, "Nên là ghé sang gửi em lời chào"},
    {47.0f, "Tút lại tóc tai chỉnh áo"},
    {50.0f, "Khi em đưa mắt sang nơi anh đây"},
    {53.0f, "Thế giới như đã mất đi một người tỉnh táo"},
};

int main()
{
    sf::Music music;
    if (!music.openFromFile("C:\\Users\\QUAN\\Music\\test.mp3"))
    {
        printf("Không thể mở file nhạc!\n");
        return -1;
    }
    music.play();

    sf::RenderWindow window(sf::VideoMode(1000, 200), "🎧 Lời bài hát đang phát 🎶");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        printf("Không tìm thấy file font arial.ttf\n");
        return -1;
    }

    sf::Text lyricText;
    lyricText.setFont(font);
    lyricText.setCharacterSize(28);
    lyricText.setFillColor(sf::Color::Cyan);
    lyricText.setPosition(30, 80);

    std::size_t currentLine = 0;

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        float currentTime = music.getPlayingOffset().asSeconds();

        // Chuyển sang câu tiếp theo nếu đến thời điểm
        if (currentLine + 1 < lyrics.size() && currentTime >= lyrics[currentLine + 1].time)
        {
            currentLine++;
        }

        lyricText.setString(lyrics[currentLine].text);

        window.clear(sf::Color::Black);
        window.draw(lyricText);
        window.display();
    }

    return 0;
}
