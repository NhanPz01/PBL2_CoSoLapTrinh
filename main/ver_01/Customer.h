class Customer {
    protected:
      string name;
      string address;
      string phone;
      string from_date;
      string to_date;
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
