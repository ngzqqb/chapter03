import sstd.register.type 1.2

RegisterObject{

    id : idThe

    property var hasTest:    try{ return test ; } catch( varError ){ return 'u' }
    property var hasTest1:   try{ return test1 ; } catch( varError ){ return 'u' }
    property var hasTest2:   try{ return test2 ; } catch( varError ){ return 'u' }
    property var hasTest3:   try{ return test3 ; } catch( varError ){ return 'u' }
    property var hasBasicV0: try{ return basicV0 ; } catch( varError ){ return 'u' }
    property var hasBasicV1: try{ return basicV1 ; } catch( varError ){ return 'u' }

    function getString(){
        return "1.2 : " +
                String(idThe.test)[0] +
                " " +
                String(idThe.test1)[0] +
                " " +
                String(idThe.test2)[0] +
                " " +
                String(idThe.test3)[0] +
                " " +
                String(idThe.basicV0)[0] +
                " " +
                String(idThe.basicV1)[0] +
                " ? " +
                String(hasTest)[0] +
                " " +
                String(hasTest1)[0] +
                " " +
                String(hasTest2)[0] +
                " " +
                String(hasTest3)[0] +
                " " +
                String(hasBasicV0)[0] +
                " " +
                String(hasBasicV1)[0] ;
    }
}

