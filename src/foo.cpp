namespace foo {
class CA
{
public:
	explicit CA(int x) {}
};
} // namespace foo

namespace foo {
class CB : public CA
{
	using CA::CA;
};
} // namespace foo

int main(){};
