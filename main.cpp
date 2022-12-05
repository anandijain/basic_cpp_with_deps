#include <fmt/core.h>
#include <cpr/cpr.h>

int main(int argc, char **argv)
{
    auto response = cpr::Get(cpr::Url{"http://httpbin.org/get"});
    cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                               cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                               cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    r.status_code;            // 200
    r.header["content-type"]; // application/json; charset=utf-8
    r.text;                   // JSON text string
    fmt::print("{}", std::string(r.text));
    return 0;
}
