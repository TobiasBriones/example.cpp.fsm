class FSM
{
	
	private:
		int state;
		
	protected:
		void setState(int);
		bool digitFSM(char);
		
	public:
		int getState();
		virtual void set(char) = 0;
		virtual void reset() = 0;
	
};

