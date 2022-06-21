#ifndef CONCRETE_DICTIONARY_HPP_
#define CONCRETE_DICTIONARY_HPP_

#include <unordered_map>
#include <iostream>
#include "dictionary_interface.hpp"

template<class Key>
class not_found_exception_mydict: public not_found_exception<Key>
{
private:
    Key key_;
public:
    not_found_exception_mydict(Key key): key_{key}
        {}

    const Key& get_key() const noexcept override
        {return key_;}
};

template<class Key, class Value>
class concrete_dictionary: public dictionary<Key,Value>
{
private:
    std::unordered_map<Key,Value> storage;
public:
    ~concrete_dictionary(){};

    const Value& get(const Key& key) const override
    {
    	auto item = storage.find(key);
    	if(nullptr==item)
    		{throw not_found_exception_mydict<Key>(key);}
    	return (*item).second;
    }

    void set(const Key& key, const Value& value) override
    {
    	const auto [it, success] = storage.insert( std::pair<Key,Value>(key,value) );
     	if(!success)
            {std::cerr << "fail set pair[" << key << "," << value << "]\n";}
    }

    bool is_set(const Key& key) const override
    {
        auto item = storage.find(key);
        if(nullptr==item)
            {return false;}
        return true;
    }

    template<class KEY, class VAL>
	friend std::ostream& operator<<(std::ostream& os, const concrete_dictionary<KEY,VAL>& dict);
};

template<class Key, class Value>
std::ostream& operator<<(std::ostream& os, const concrete_dictionary<Key,Value>& dict)
{
    for(const auto& item : dict.storage)
    {
        os << "first=" << item.first << "  " << "second=" << item.second << '\n';
    }
    return os;
}

#endif /* CONCRETE_DICTIONARY_HPP_ */
