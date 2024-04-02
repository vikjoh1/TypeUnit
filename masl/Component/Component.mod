domain Component is
  object WasRun;
  object TestCase;
  object TestCaseTest;
    private service refineTest (
    );
    private service wasRun (
        name : in string    );
    private service run (
    );
  relationship R1 is WasRun conditionally Is_a_type_of one TestCase,
    TestCase unconditionally specializes_into one WasRun;
  object WasRun is
    wasRun :   boolean;
    name :   string;
    public instance service run (
    );
    public instance service setUp (
    );
    creation state NotRun();
     state Running();
    terminal state Passed();
    terminal state Failed();
    creation event callConstructor();
     event run();
     event fail();
     event pass();
     transition is
      Non_Existent (
        callConstructor => NotRun,
        run => Cannot_Happen,
        fail => Cannot_Happen,
        pass => Cannot_Happen      ); 
      NotRun (
        callConstructor => Cannot_Happen,
        run => Running,
        fail => Cannot_Happen,
        pass => Cannot_Happen      ); 
      Running (
        callConstructor => Cannot_Happen,
        run => Cannot_Happen,
        fail => Failed,
        pass => Passed      ); 
      Passed (
        callConstructor => Cannot_Happen,
        run => Cannot_Happen,
        fail => Cannot_Happen,
        pass => Cannot_Happen      ); 
      Failed (
        callConstructor => Cannot_Happen,
        run => Cannot_Happen,
        fail => Cannot_Happen,
        pass => Cannot_Happen      ); 
    end transition;
  end object;
  object TestCase is
    name :   string;
    public instance service run (
    );
    public instance service setUp (
    );
     state Idle();
     state Running();
     state Completed();
     event execute();
     event finish();
     transition is
      Non_Existent (
        execute => Cannot_Happen,
        finish => Cannot_Happen      ); 
      Idle (
        execute => Running,
        finish => Cannot_Happen      ); 
      Running (
        execute => Cannot_Happen,
        finish => Completed      ); 
      Completed (
        execute => Cannot_Happen,
        finish => Cannot_Happen      ); 
    end transition;
  end object;
  object TestCaseTest is
    public instance service testRunning (
    );
  end object;
end domain;
