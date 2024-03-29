domain Component is
  object WasRun;
  object TestCaseTest;
  object TestCase;
  relationship R1 is WasRun conditionally Is_a_type_of one TestCase,
    TestCase unconditionally specializes_into one WasRun;
  object WasRun is
    wasRun :   boolean;
    name :   string;
    public instance service run (
    );
    public instance service constructor (
        name : in string    );
  end object;
  object TestCaseTest is
    public instance service testRunning (
    );
  end object;
  object TestCase is
    name :   string;
    public instance service run (
    );
    public instance service constructor (
        name : in string    );
  end object;
end domain;
