#include <rfl-version.hpp>
#include <rfl/json.hpp>
#include <rfl.hpp>

// Age must be a plausible number, between 0 and 130. This will
// be validated automatically.
using Age = rfl::Validator<int, rfl::Minimum<0>, rfl::Maximum<130>>;

struct Person
{
    rfl::Rename<"firstName", std::string> first_name;
    rfl::Rename<"lastName", std::string> last_name = "Simpson";
    std::string town = "Springfield";
    rfl::Timestamp<"%Y-%m-%d"> birthday;
    Age age;
    rfl::Email email;
    std::vector<Person> children;
};

int main()
{

    const auto bart = Person{.first_name = "Bart",
                            .birthday = "1987-04-19",
                            .age = 10,
                            .email = "bart@simpson.com"};

    const auto lisa = Person{.first_name = "Lisa",
                            .birthday = "1987-04-19",
                            .age = 8,
                            .email = "lisa@simpson.com"};

    const auto maggie = Person{.first_name = "Maggie",
                            .birthday = "1987-04-19",
                            .age = 0,
                            .email = "maggie@simpson.com"};


    const auto homer =
        Person{.first_name = "Homer",
               .birthday = "1987-04-19",
               .age = 45,
               .email = "homer@simpson.com",
               .children = std::vector<Person>({bart, lisa, maggie})};

    // We can now transform this into a JSON string.
    const std::string json_string = rfl::json::write(homer);
    std::cout << json_string << std::endl;

    // We can also directly write into std::cout (or any other std::ostream).
    rfl::json::write(homer, std::cout) << std::endl;
}
