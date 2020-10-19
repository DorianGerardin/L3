package test;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SUTTest {
    SUT sut;

    @BeforeEach
    void setUp() {
        //sut=new SUT();
    }

    @Test
    void foobar() {
        SUT sut = new SUT(-1, 2, 3);
        assertThrows(FooBarException.class, sut::foobar);
    }
}