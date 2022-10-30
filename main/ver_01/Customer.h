class Customer {
    protected:
      string name[100];
      string address[100];
      string phone[12];
      string from_date[20];
      string to_date[20];
      float payment_advance;
      int booking_id;
    public:
          Customer();
          ~Customer();
          void setName(string&);
          void setAddress(string&);
          void setPhone(string&);
          void setFromDate(string&);
          void setToDate(string&);
          void setPaymentAdvance(float);
          void setBookingId(int);
          string getName() const;
          string getAddress() const;
          string getPhone() const;
          string getFromDate() const;
          string getToDate() const;
          float getPaymentAdvance() const;
          int getBookingId() const;
};
