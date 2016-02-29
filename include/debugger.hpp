#ifndef DEBUGGER
#define DEBUGGER




class Debugger
{
public:
	void set(bool);

	void debug(std::ostream &, const std::string &);

	void debug(const std::string &);

	static Debugger & instance();

private:
	bool _activate;

	static Debugger d;

	Debugger();

	~Debugger();
	
	// to avoid the copy of the singleton
	
	Debugger(const Debugger &);

	void operator = (const Debugger &);
	
};

#endif