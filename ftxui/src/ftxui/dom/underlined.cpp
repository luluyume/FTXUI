#include "ftxui/dom/node_decorator.hpp"
#include "ftxui/dom/elements.hpp"

namespace ftxui {

using ftxui::Screen;

class Underlined : public NodeDecorator {
 public:
  Underlined(Elements children) : NodeDecorator(std::move(children)) {}
  ~Underlined() override {}

  void Render(Screen& screen) override {
    Node::Render(screen);
    for (int y = box_.top; y <= box_.bottom; ++y) {
      for (int x = box_.left; x <= box_.right; ++x) {
        screen.PixelAt(x, y).underlined = true;
      }
    }
  }
};

std::unique_ptr<Node> underlined(Element child) {
  return std::make_unique<Underlined>(unpack(std::move(child)));
}

};  // namespace ftxui