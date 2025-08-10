#ifndef PLUGUN_BASE_HPP
#define PLUGIN_BASE_HPP

namespace pkg_a {

class BaseInterface {
public:
    virtual ~BaseInterface() = default;

    virtual int placeholder(int arg) = 0;
};

} // namespace plugin_base

#endif
